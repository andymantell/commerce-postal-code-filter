<?php

/**
 * @file
 * Form callbacks and validate / submit functions
 */

/**
 * Form callback for delivery check block
 */
function commerce_postal_code_filter_delivery_check($form, &$form_state) {

  $form['postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#size' => 15,
  );

  $form['postal_code_validity'] = array(
    '#prefix' => '<div id="postal-code-validity">',
    '#suffix' => '</div>',
  );

  if (!empty($form_state['values']['postal_code'])) {

    if (_commerce_postal_code_filter_postal_code_is_valid($form_state['values']['postal_code'])) {
      $form['postal_code_validity']['#markup'] = '<p class="commerce-postcode-filter-valid">' . variable_get('commerce_postal_code_filter_block_success_message', 'Good news! We can deliver to this postal code.') . '</p>';
    }
    else {
      $form['postal_code_validity']['#markup'] = '<p class="commerce-postcode-filter-invalid">' . variable_get('commerce_postal_code_filter_block_error_message', 'Sorry, We do not deliver to this postal code.') . '</p>';
    }
  }

  $form['check'] = array(
    '#type' => 'button',
    '#value' => t('Check postal code'),
    '#ajax' => array(
      'callback' => 'commerce_postal_code_filter_delivery_check_ajax_callback',
      'wrapper' => 'postal-code-validity',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'commerce_postal_code_filter') . '/commerce_postal_code_filter.css';

  return $form;

}

/**
 * Ajax callback for delivery check form
 */
function commerce_postal_code_filter_delivery_check_ajax_callback($form, $form_state) {

  return $form['postal_code_validity'];

}
