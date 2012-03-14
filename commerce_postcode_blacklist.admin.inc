<?php

/**
 * Form callback for the postcode blacklist admin form
 */
function commerce_postcode_blacklist_configure() {

  $form = array();

  $form['commerce_postcode_blacklist'] = array(
    '#type' => 'textarea',
    '#title' => t('Postcode blacklist'),
    '#description' => t('Blacklisted postcodes, comma seperated. Partial postcodes are supported, e.g. PL, EX5'),
    '#default_value' => str_replace(',', ', ', variable_get('commerce_postcode_blacklist', '')),    // Add spaces between the commas when displayed in the form, these are removed again on submit
  );
  
  $form['commerce_postcode_blacklist_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#required' => TRUE,
    '#description' => t('Error message to display when a customer tries to use a blacklisted postcode'),
    '#default_value' => variable_get('commerce_postcode_blacklist_message', 'We do not deliver to this postcode'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save blacklist',
  );

  return $form;

}

/**
 * Submit callback for the postcode blacklist admin form
 */
function commerce_postcode_blacklist_configure_submit($form, &$form_state) {

  // Fetch the blacklist from the form state and force it to be uppercase
  $blacklist = strtoupper($form_state['values']['commerce_postcode_blacklist']);

  // Remove all whitespace
  $blacklist = preg_replace('/\s+/', '', $blacklist);

  // Save it to our variable
  variable_set('commerce_postcode_blacklist', $blacklist);
  
  // Save the error message to a variable
  variable_set('commerce_postcode_blacklist_message', $form_state['values']['commerce_postcode_blacklist_message']);

}