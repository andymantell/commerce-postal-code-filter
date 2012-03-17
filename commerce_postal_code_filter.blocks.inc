<?php

/**
 * @file
 * Block hook implementations
 */

/**
 * Implements hook_block_info().
 */
function commerce_postal_code_filter_block_info() {

  $blocks = array();

  $blocks['delivery-check'] = array(
    'info' => t('Commerce Postal Code Filter - Delivery check'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );

  return $blocks;

}

/**
 * Implements hook_block_view().
 */
function commerce_postal_code_filter_block_view($delta = '') {

  switch ($delta) {

    case 'delivery-check':
      return array(
        'subject' => t('Do we deliver to your area?'),
        'content' => array(
          'description' => array(
            '#prefix' => '<p>',
            '#markup' => t('Enter your postal code below and check to see if we deliver to your area.'),
            '#suffix' => '</p>',
          ),
          'delivery-check-form' => drupal_get_form('commerce_postal_code_filter_delivery_check'),
        ),
      );

      break;
  }

}

/**
 * Implements hook_block_configure().
 */
function commerce_postal_code_filter_block_configure($delta = '') {

  switch ($delta) {

    case 'delivery-check':
      $form = array();

      $form['commerce_postal_code_filter_block_error_message'] = array(
        '#type' => 'textfield',
        '#title' => t('Error message'),
        '#required' => TRUE,
        '#description' => t('Error message to display when a customer checks a postcode that is not acceptable'),
        '#default_value' => variable_get('commerce_postal_code_filter_block_error_message', 'Sorry, We do not deliver to this postal code.'),
      );

      $form['commerce_postal_code_filter_block_success_message'] = array(
        '#type' => 'textfield',
        '#title' => t('Success message'),
        '#required' => TRUE,
        '#description' => t('Message to display when a customer checks a postcode that is acceptable'),
        '#default_value' => variable_get('commerce_postal_code_filter_block_success_message', 'Good news! We can deliver to this postal code.'),
      );

      return $form;

      break;

  }

}

/**
 * Implements hook_block_save().
 */
function commerce_postal_code_filter_block_save($delta = '', $edit = array()) {

  switch ($delta) {

    case 'delivery-check':
      variable_set('commerce_postal_code_filter_block_success_message', $edit['commerce_postal_code_filter_block_success_message']);
      variable_set('commerce_postal_code_filter_block_error_message', $edit['commerce_postal_code_filter_block_error_message']);

      break;

  }

}
