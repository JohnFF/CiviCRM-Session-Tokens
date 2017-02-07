<?php

/**
* Extend taxonomy term field handler with tokens for pretty paths.
*
* @ingroup views_field_handlers
*/
class civicrm_user_connected_orgs_field_term_path extends views_handler_field_field {

  function
document_self_tokens(&$tokens) {
    watchdog('civicrm_user_connected_orgs', '1' , array(), WATCHDOG_ERROR);
    $field = $this->field_info;
    foreach ($field['columns'] as $id => $column) {
      $tokens['[' . $this->options['id'] . '-' . $id . ']'] = t('Raw @column', array('@column' => $id));
      $tokens['[' . $this->options['id'] . '-' . 'term-pretty-path]'] = t('Term pretty path');
      $tokens['[' . $this->options['id'] . '-' . 'vocabulary-pretty-path]'] = t('Vocabulary pretty path');
    }
  }

  function
add_self_tokens(&$tokens, $item) {
    watchdog('civicrm_user_connected_orgs', '2' , array(), WATCHDOG_ERROR);
    $field = $this->field_info;
    foreach ($field['columns'] as $id => $column) {
      // Use filter_xss_admin because it's user data and we can't be sure it is safe.
      // We know nothing about the data, though, so we can't really do much else.

     
if (isset($item['raw'])) {
        // If $item['raw'] is an array then we can use as is, if it's an object
        // we cast it to an array, if it's neither, we can't use it.
        $raw = is_array($item['raw']) ? $item['raw'] :
               (is_object($item['raw']) ? (array)$item['raw'] : NULL);
      }
      if (isset($raw) && isset($raw[$id]) && is_scalar($raw[$id])) {
        $path_string = $raw[$id];
        $path = explode('/', $path_string);
        $tokens['[' . $this->options['id'] . '-term-pretty-path]'] = $path[1];
        $tokens['[' . $this->options['id'] . '-vocabulary-pretty-path]'] = $path[0];
      }
      else {
        // Take sure that empty values are replaced as well.
        $tokens['[' . $this->options['id'] . '-term-pretty-path]'] = '';
        $tokens['[' . $this->options['id'] . '-vocabulary-pretty-path]'] = '';
      }
    }
  }
}


