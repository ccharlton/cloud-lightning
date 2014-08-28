<?php

/*
 * Acquia Cloud settings.php configuration
 *
 * Copy, paste, and edit the below or include this file and edit.
 * ... all of this comes after the default settings.php file.
 *
 * Note: Acquia Cloud Free accounts do not support Custom Domains or Prod servers.
 */


// Database settings
if (file_exists('/var/www/site-php')) {
    require '/var/www/site-php/ACCOUNT/EXAMPLE-settings.inc';  // EDIT OR REMOVE THIS
}

// Memcache (hardcode 'cache_backends' path below to remove IF statement)
if (file_exists('./sites/all/modules/contrib/memcache/memcache.inc')) {
  $conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
}
else if (file_exists('./sites/all/modules/memcache/memcache.inc')) {
  $conf['cache_backends'][] = './sites/all/modules/memcache/memcache.inc';
}
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

/**
 * Alter site configs & variables based on the cloud server environment.
 *
 * @see https://library.acquia.com/articles/environment-variables-acquia-cloud
 */
if (!empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
    $files_private_conf_path = conf_path();
    $conf['file_private_path'] = '/mnt/files/' . $_ENV['AH_SITE_GROUP'] . '.' . $_ENV['AH_SITE_ENVIRONMENT'] . '/' . $files_private_conf_path . '/files-private';
  }
  else {
    # $conf['file_private_path'] = '{PATH}'; // Local development path, or a default you choose.
  }


  // Swap settings based on environment
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    ////////////////////////////
    // Dev
    ////////////////////////////
    case 'dev':
      // Apache Solr index READ ONLY
      $conf['apachesolr_read_only'] = "1";

      // Acquia Purge (acquia_purge)
      $conf['acquia_purge_domains'] = array(
        'dev.example.com',
      );

      // Update Status report notification emails OFF
      $conf['update_notify_emails'] = array();

	    // Error display
      $conf['error_level'] = '2';

	    // Caching:
      // Caching for anonymous visitors
	    # $conf['cache'] = '1';
	    // Block caching - enabled.
	    # $conf['block_cache'] = '1';
	    // Expiration of cached pages - 15 minutes.
	    # $conf['page_cache_maximum_age'] = '900';
	    // Minimum cache lifetime - always none.
  	  # $conf['cache_lifetime'] = '0';
  	  // Cached page compression - on.
	    # $conf['page_compression'] = '1';
	    // Aggregate and compress CSS files in Drupal - on.
	    # $conf['preprocess_css'] = '1';
	    // Aggregate JavaScript files in Drupal - on.
	    # $conf['preprocess_js'] = '1';

    break;

    ////////////////////////////
    // Staging/Test
    ////////////////////////////
    case 'test':
      // Apache Solr index READ ONLY
      $conf['apachesolr_read_only'] = "1";

      // Acquia Purge (acquia_purge)
      $conf['acquia_purge_domains'] = array(
      	'test.example.com',
      );

      // Update Status report notification emails OFF
      $conf['update_notify_emails'] = array();

	    // Error display
      $conf['error_level'] = '0';

	    // Caching:
      // Caching for anonymous visitors
	    $conf['cache'] = '1';
	    // Block caching - enabled.
	    $conf['block_cache'] = '1';
	    // Expiration of cached pages - 15 minutes.
	    $conf['page_cache_maximum_age'] = '900';
	    // Minimum cache lifetime - always none.
  	  $conf['cache_lifetime'] = '0';
  	  // Cached page compression - on.
	    $conf['page_compression'] = '1';
	    // Aggregate and compress CSS files in Drupal - on.
	    $conf['preprocess_css'] = '1';
	    // Aggregate JavaScript files in Drupal - on.
	    $conf['preprocess_js'] = '1';

    break;

    ////////////////////////////
    // Prod
    ////////////////////////////
    case 'prod':

      // Apache Solr index READ/WRITE
      # $conf['apachesolr_read_only'] = "0";

      // Acquia Purge (acquia_purge)
      $conf['acquia_purge_domains'] = array(
      	'example.com',
      );

      // Update Status report notification emails
      # $conf['update_notify_emails'] = array();

	    // Error display
      $conf['error_level'] = '0';

	    // Caching:
      // Caching for anonymous visitors
	    $conf['cache'] = '1';
	    // Block caching - enabled.
	    $conf['block_cache'] = '1';
	    // Expiration of cached pages - 15 minutes.
	    $conf['page_cache_maximum_age'] = '900';
	    // Minimum cache lifetime - always none.
  	  $conf['cache_lifetime'] = '0';
  	  // Cached page compression - on.
	    $conf['page_compression'] = '1';
	    // Aggregate and compress CSS files in Drupal - on.
	    $conf['preprocess_css'] = '1';
	    // Aggregate JavaScript files in Drupal - on.
	    $conf['preprocess_js'] = '1';

    break;

    ////////////////////////////
    // Default (Local/Test Env.)
    ////////////////////////////
    default:
	    // Error display
      $conf['error_level'] = '2';

      // Apache Solr index READ ONLY
      $conf['apachesolr_read_only'] = "1";

      // Acquia Purge (acquia_purge)
      $conf['acquia_purge_domains'] = array();

      // Update Status report notification emails OFF
      $conf['update_notify_emails'] = array();

    break;

  }
}
