<?php

/**
 * @file
 * Contains form callback and submit function for the postal code admin form
 */

/**
 * Form callback for the postal code filter admin form
 */
function commerce_postal_code_filter_ui_configure() {

  $form = array();

  $form['commerce_postal_code_filter_postal_codes'] = array(
    '#type' => 'textarea',
    '#title' => t('Postal code filter'),
    '#description' => t('Postal codes to be filtered, comma seperated. Partial postal codes are supported, e.g. PL, EX5'),
    // Add spaces between the commas when displayed in the form.
    // These are removed again on submit.
    '#default_value' => str_replace(
      ',',
      ', ',
      variable_get('commerce_postal_code_filter_postal_codes', '')
    ),
  );

  $form['commerce_postal_code_filter_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Filter mode'),
    '#required' => TRUE,
    '#description' => t('Whether to "blacklist" or "whitelist" postcodes. If blacklisted, postcodes in the above filter will be prevented from completing checkout. If whitelisted, <em>only</em> postcodes that are in the above filter will be allowed to checkout'),
    '#default_value' => variable_get('commerce_postal_code_filter_mode', 'blacklist'),
    '#options' => array(
      'blacklist' => t('Blacklist'),
      'whitelist' => t('Whitelist'),
    ),
  );

  $form['commerce_postal_code_filter_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#required' => TRUE,
    '#description' => t('Error message to display when a customer tries to use a filtered postal code'),
    '#default_value' => variable_get('commerce_postal_code_filter_message', 'Sorry, We do not deliver to this postal code'),
  );

  // Delivery block.
  $form['commerce_postal_code_delivery_block'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Delivery check block'),
    '#description' => t('Message configuration options for the delivery check block, allowing customers to check postcodes before checking out.'),
  );

  $form['commerce_postal_code_delivery_block']['commerce_postal_code_filter_block_error_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#required' => TRUE,
    '#description' => t('Error message to display when a customer checks a postcode that is not acceptable'),
    '#default_value' => variable_get('commerce_postal_code_filter_block_error_message', 'Sorry, We do not deliver to this postal code.'),
  );

  $form['commerce_postal_code_delivery_block']['commerce_postal_code_filter_block_success_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Success message'),
    '#required' => TRUE,
    '#description' => t('Message to display when a customer checks a postcode that is acceptable'),
    '#default_value' => variable_get('commerce_postal_code_filter_block_success_message', 'Good news! We can deliver to this postal code.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save postal code filter options'),
  );

  return $form;

}

/**
 * Submit callback for the postal code filter admin form
 */
function commerce_postal_code_filter_ui_configure_submit($form, &$form_state) {

  // Fetch the filter list from the form state and force it to be uppercase.
  $postal_codes = drupal_strtoupper($form_state['values']['commerce_postal_code_filter_postal_codes']);

  // Remove all whitespace.
  $postal_codes = preg_replace('/\s+/', '', $postal_codes);

  // Save it to our variable.
  variable_set('commerce_postal_code_filter_postal_codes', $postal_codes);
  variable_set('commerce_postal_code_filter_mode', $form_state['values']['commerce_postal_code_filter_mode']);
  variable_set('commerce_postal_code_filter_message', $form_state['values']['commerce_postal_code_filter_message']);

  drupal_set_message(t('The configuration options have been saved.'));

}
