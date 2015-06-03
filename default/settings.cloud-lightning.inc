<?php

/*
 * Generic cloud settings.php configuration
 *
 * Copy, paste, and edit the below or include this file and edit.
 * ... all of this comes after the default settings.php file.
 *
 */


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
 * Alter site configs & variables based on the server environment.
 *
 */
$server_env = 'prod'; // Values: dev, test, prod

if (!empty($server_env)) {
  if (isset($server_env)) {
    $files_private_conf_path = conf_path(); // Not used, but ready for you to use.
    $conf['file_temporary_path'] = '/tmp'; // EDIT THIS (full path)
    $conf['file_private_path'] = '/var/www/files-private'; // EDIT THIS (full path)
    $conf['file_public_path'] = 'files'; // EDIT THIS (relative path)
  }
  else {
    $conf['file_temporary_path'] = '/tmp'; // Local full path, or a default you choose.
    # $conf['file_private_path'] = '{PATH}'; // Local full path, or a default you choose.
    # $conf['file_public_path'] = 'files'; // Local releative path, or a default you choose.
  }


  // Swap settings based on environment
  switch ($server_env) {
    ////////////////////////////
    // Dev
    ////////////////////////////
    case 'dev':
      // Apache Solr index READ ONLY
      $conf['apachesolr_read_only'] = "1";

      // Update Status report notification emails OFF
      $conf['update_notify_emails'] = array();

      // Error display
      $conf['error_level'] = '2';

	    // Secure Pages
      # $conf['securepages_enable'] = FALSE;

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

      // Update Status report notification emails OFF
      $conf['update_notify_emails'] = array();

	    // Error display
      $conf['error_level'] = '0';

      // Secure Pages
      # $conf['securepages_enable'] = FALSE;

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

      // Update Status report notification emails
      # $conf['update_notify_emails'] = array();

	    // Error display
      $conf['error_level'] = '0';

      // Secure Pages
      # $conf['securepages_enable'] = FALSE;

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

      // Update Status report notification emails OFF
      $conf['update_notify_emails'] = array();

      // Secure Pages
      # $conf['securepages_enable'] = FALSE;

    break;

  }
}
