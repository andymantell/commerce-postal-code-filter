<?php

/**
 * @file
 * Hooks provided by Commerce postcode blacklist.
 */

/**
 * Main hook which should be implemented to provide postcodes to blacklist
 *
 * Postcodes should be returned without spaces and in uppercase
 * Postcodes can be full or partial, allowing whole areas to be blacklisted
 *
 * @return array List of postcodes to return
 */
function hook_commerce_postcode_blacklist_postcodes() {
  return array(
    'EX4',
    'PL1',
    'PL18BC'
  )
}
