<?php

class ExtendedCFTypeDetector extends CFTypeDetector {
  public function __construct($autoDicitionary = FALSE, $suppressExceptions = FALSE) {
    super::__construct($autoDicitionary, $suppressExceptions);
  }

  public function toCFType($value) {
    if (is_object($value)) {
      $value = get_object_vars($value);
    }
    return super::toCFType($value);
  }
}