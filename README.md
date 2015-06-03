Cloud Lightning for Drupal
==========================

Effective [Drupal](http://drupal.org) `settings.php` configurations for popular clouds and hosting providers.

These scripts provide easy activation of best practices, effective settings, and developer favorites.

![Cloud Lightning for Drupal](https://github.com/ccharlton/cloud-lightning/raw/master/misc/assets/img/cloud_lightning_for_drupal-banner.png)

###Purpose of this project

To help everyone who is deploying Drupal in the cloud. Why else?

Developers don't like wasting time and people who don't turn on the right settings think Drupal is slow. This can be easier. This collection of Drupal includes don't require any modifications to Drupal core, only a simple minor change to your `settings.php` file to provide better out-of-the-box performance when hosted on popular cloud providers.

Clouds Supported
================

- Acquia Cloud - http://acquia.com (Drupal 7.x supported)
- No Cloud (generic DIY servers/clouds)

#### Planned support for other providers
- Pantheon - http://getpantheon.com
- TBD

How to use this project
=======================

1. Always refer to your cloud provider's official documentation; they may change at any time.
2. Paste or include the snippet for your cloud at the bottom of `settings.php`.
3. Deploy. Clear caches. Watch the lightning happen.

Editing `settings.php`
----------------------

Either method below will work. One method isn't better over the other; don't overthink it.

The official [Drupal `$conf` array documentation](https://www.drupal.org/node/1525472) is available if you want to know what other core variables you can customize.

Simple Copy+Paste Method: (non-working example)
-----------------------------------------------

You can simply append cloud-lightning to your site, which is totally fine, by pasting the entire cloud provider code at the bottom of your `settings.php` file.

```php
// End of `settings.php` above...

// ACME Co. cloud settings
if (file_exists('/var/www/site-php')) {
    require '/var/www/site-php/example.com/example-settings.inc'; // EDIT THIS
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

Pro Include Method:
-----------------------------------------

For those who prefer to include these settings. Good for multi-site Drupal installs or to maintain cloud settings separately.

```php
// End of `settings.php` above...

// NOTE: same folder as `settings.php`
$cloud_provider_inc = 'cloud-lightning/provider/settings.cloud-provider.inc'; // EDIT THIS
if (file_exists(dirname(__FILE__).'/'.$cloud_provider_inc)) {
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
