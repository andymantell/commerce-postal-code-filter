Commerce Postcode Filter
------------------------
Postal code filtering functionality for the Drupal Commerce checkout process.
This module provides 2 main modes (whitelisting and blacklisting) which allow
shop owners to restrict the areas of a country that they deliver to:

Blacklisting
If a customer tries to complete checkout with a postcode that is on the
blacklist, they will be prevented from doing so. This allows shop owners to
exclude a certain part of the country.

Whitelisting
If a customer tries to complete checkout with a postcode that is not on the
whitelist, they will be prevented from doing so. This allows shop owners to
include only a small part of the country (e.g. they may wish only to accept
orders from their locality. A whitelist allows them to do so without needing
to exhaustively list all the postal codes that they do not accept)

Partial matches
Matches in both modes are done on partial postcodes, so the blacklist could
contain "PL" which would prevent the postcode PL5 4AB from being submitted.
Similarly you could <em>whitelist</em> only the "PL" postal code, which would
prevent the postcode "BS3 4BC" from being submitted.

Postcode checking block
The core module exposes a postcode checking block allowing customers to check
their postcode before proceeding to the checkout.

This module depends on Drupal Commerce and commerce_shipping-2.x
(http://drupal.org/project/commerce_shipping).

Currently the module filters shipping addresses provided by this module.
In future, this module will provide the option to filter billing addresses as
well, at which point I will make commerce_shipping optional.
