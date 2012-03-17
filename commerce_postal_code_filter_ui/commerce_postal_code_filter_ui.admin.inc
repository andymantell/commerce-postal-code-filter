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

  $form['commerce_postal_code_filter_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#required' => TRUE,
    '#description' => t('Error message to display when a customer tries to use a filtered postal code'),
    '#default_value' => variable_get('commerce_postal_code_filter_message', 'We do not deliver to this postal code'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save postal code filter'),
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

  // Save the error message to a variable.
  variable_set('commerce_postal_code_filter_message', $form_state['values']['commerce_postal_code_filter_message']);

}
