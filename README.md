Cloud Lightning for Drupal
==========================

Effective [Drupal](http://drupal.org) settings.php configs for popular cloud hosting providers.

These scripts provide easy activation of best practices, effective settings, and developer favorites. Add these settings to your Drupal sites in the cloud!

![Cloud Lightning for Drupal](https://github.com/ccharlton/cloud-lightning/raw/master/misc/assets/img/cloud_lightning_for_drupal-banner.png)

###Purpose of this project

To help everyone who is deploying Drupal in the cloud. Why else?

Developers don't like wasting time and people who don't turn on the right settings think Drupal is slow. This can be easier. So this collection of Drupal settings.php includes/overrides don't require any modifications to Drupal core and only a simple minor change to your `settings.php` file to provide better out-of-the-box performance when hosted on popular Cloud providers.

Clouds Supported
================

- Acquia Cloud - http://acquia.com (Drupal 7.x supported)

#### Support for other providers

- Pantheon - http://getpantheon.com
- TBD

How to use this project
=======================

1. Always refer to your cloud provider's official documentation; they may change at any time.
2. Paste or include the snippet for your cloud provider at the bottom of `settings.php`.
3. Deploy. Clear caches. Watch the magic happen.

Editing `settings.php`
----------------------

Either method below will work. One method isn't better over the other; don't overthink it.

Easy Method: Copy + Paste (non-working example)
-----------------------------------------------

If you want to append the settings to your PHP file, which is totally fine, then copy and paste the include snippets into your settings.php file.

```php
// Standard `settings.php` (above) ...

// ACME Co. cloud settings (DO NOT USE)
if (file_exists('/var/www/site-php')) {
    require '/var/www/site-php/example/example-settings.inc'; // EDIT THIS
}

$conf[super_special_config]   = '1';
$conf[speed_plugin_go_faster] = '1';
$conf[sharks_with_lasers]     = '1';
$conf[caching_layer_include]  = './sites/all/modules/xxx/xxx.inc'; // EDIT THIS

switch ($_ENV['ACME_CO_ENVIRONMENT']) {
  case 'dev':
    // Shut stuff off. Turn stuff on.
    break;

  case 'prod':
    // "I'm giving her all she's got, Captain!"   --Famous Engineer
    break;
}
```

Pro Method: Include (non-working example)
-----------------------------------------

For those who prefer to include this file that works as well. Good for multi-site Drupal installs, or to track cloud connection/settings separately.

```php
// Standard `settings.php` (above) ...

// NOTE: same folder as `settings.php`
$cloud_provider_inc = 'cloud-lightning/provider/settings.example.inc'; // EDIT THIS
if (file_exists(dirname(__FILE__).'/'.$cloud_provider_inc)) {}
  require $cloud_provider_inc;
}
```

#Team

Chris Charlton (Los Angeles Drupal) http://chrischarlton.us

Support
=======

If you have a feature or issue you'd like to file, please visit: https://github.com/ccharlton/cloud-lightning/issues

**Social Network Hashtag:** *#CloudLightning4Drupal*

### FAQ

**Don't have Memcache installed on your local development machine?** Move that portion of code inside the Environment checks.

**Do I have to clone this project's Git repo to use the includes?** No. Clone. Copy. Download. Whatever works for you.
