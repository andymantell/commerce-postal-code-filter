<?php

/**
 * @file
 * Contains form callback and submit function for the postal code admin form
 */

/**
 * Form callback for the postal code filter admin form
 */
function commerce_postal_code_filter_configure() {

  $form = array();

  $config = variable_get('commerce_postal_code_filter_config', array());

  $form['postal_codes'] = array(
    '#type' => 'textarea',
    '#title' => t('Postal code filter'),
    '#description' => t('Postal codes to be filtered, comma seperated. Partial postal codes are supported, e.g. PL, EX5'),
    // Add spaces between the commas when displayed in the form.
    // These are removed again on submit.
    '#default_value' => empty($config['postal_codes']) ? '' : str_replace(',', ', ', $config['postal_codes']),
  );

  $form['filter_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Filter mode'),
    '#required' => TRUE,
    '#description' => t('Whether to "blacklist" or "whitelist" postcodes. If blacklisted, postcodes in the above filter will be prevented from completing checkout. If whitelisted, <em>only</em> postcodes that are in the above filter will be allowed to checkout'),
    '#default_value' => empty($config['filter_mode']) ? 'blacklist' : $config['filter_mode'],
    '#options' => array(
      'blacklist' => t('Blacklist'),
      'whitelist' => t('Whitelist'),
    ),
  );

  $form['filter_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#required' => TRUE,
    '#description' => t('Error message to display when a customer tries to use a filtered postal code'),
    '#default_value' => empty($config['filter_message']) ? 'Sorry, We do not deliver to this postal code' : $config['filter_message'],
  );

  // Delivery block.
  $form['delivery_block'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Delivery check block'),
    '#description' => t('Message configuration options for the delivery check block, allowing customers to check postcodes before checking out.'),
    '#tree' => TRUE,
  );

  $form['delivery_block']['error_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#required' => TRUE,
    '#description' => t('Error message to display when a customer checks a postcode that is not acceptable'),
    '#default_value' => empty($config['delivery_block']['error_message']) ? 'Sorry, We do not deliver to this postal code.' : $config['delivery_block']['error_message'],
  );

  $form['delivery_block']['success_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Success message'),
    '#required' => TRUE,
    '#description' => t('Message to display when a customer checks a postcode that is acceptable'),
    '#default_value' => empty($config['delivery_block']['success_message']) ? 'Good news! We can deliver to this postal code.' : $config['delivery_block']['success_message'],
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
function commerce_postal_code_filter_configure_submit($form, &$form_state) {

  // Fetch the filter list from the form state and force it to be uppercase.
  $form_state['values']['postal_codes'] = drupal_strtoupper($form_state['values']['postal_codes']);

  // Remove all whitespace.
  $form_state['values']['postal_codes'] = preg_replace('/\s+/', '', $form_state['values']['postal_codes']);

  form_state_values_clean($form_state);
  variable_set('commerce_postal_code_filter_config', $form_state['values']);

  drupal_set_message(t('The configuration options have been saved.'));

}
