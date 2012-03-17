<?php

/**
 * @file
 * Hooks provided by Commerce postal code filter.
 */

/**
 * Main hook which should be implemented to provide postal codes to filter
 *
 * Postal codes should be returned without spaces and in uppercase
 * Postal codes can be full or partial, allowing whole areas to be filtered
 *
 * @return array
 *   List of postal codes to return
 */
function hook_commerce_postal_code_filter_postal_codes() {
  return array(
    'EX4',
    'PL1',
    'PL18BC',
  );
}
