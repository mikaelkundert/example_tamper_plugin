<?php

$plugin = array(
  'form' => 'example_tamper_plugin_str_pad_form',
  'callback' => 'example_tamper_plugin_str_pad_callback',
  'name' => 'Custom pad',
);

/**
 * Callback for specifying settings form for this plugin.
 */
function example_tamper_plugin_str_pad_form($importer, $element_key, $settings) {
  $form = array();
  $form['length'] = array(
    '#type' => 'textfield',
    '#title' => t('Length'),
    '#description' => t('If the value of length is negative, less than, or equal to the length of the input string, no padding takes place.'),
    '#default_value' => isset($settings['length']) ? $settings['length'] : '',
    '#size' => 4,
    '#required' => TRUE,
  );
  $form['string'] = array(
    '#type' => 'textfield',
    '#title' => t('String'),
    '#size' => 10,
    '#description' => t('The string may be truncated if the required number of padding characters can\'t be evenly divided by the string\'s length.'),
    '#default_value' => isset($settings['string']) ? $settings['string'] : ' ',
  );
  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Type'),
    '#options' => array(STR_PAD_RIGHT => t('Right'), STR_PAD_LEFT => t('Left'), STR_PAD_BOTH => t('Both')),
    '#default_value' => isset($settings['type']) ? $settings['type'] : STR_PAD_RIGHT,
  );
  return $form;
}

/**
 * Callback to run the tampering.
 */
function example_tamper_plugin_str_pad_callback($result, $item_key, $element_key, &$field, $settings) {
  $type = isset($settings['type']) && in_array($settings['type'], array(STR_PAD_RIGHT, STR_PAD_LEFT, STR_PAD_BOTH)) ? $settings['type'] : STR_PAD_RIGHT;
  $field = str_pad($field, intval($settings['length']), $type);
}
