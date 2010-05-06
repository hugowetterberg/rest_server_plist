<?php

class RESTServerPlistView extends RESTServerView {
  public function render() {
    // Construct our plist
    $detector = new ExtendedCFTypeDetector(FALSE, TRUE);
    $cfdata = $detector->toCFType($this->model);
    $plist = new CFPropertyList();
    $plist->add($cfdata);

    $data = NULL;
    switch ($this->arguments['format']) {
      case 'xml':
        $data = $plist->toXML();
        break;
      default:
        $data = $plist->toBinary();
        break;
    }
    return $data;
  }
}