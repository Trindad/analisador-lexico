<?php

class Buffer
{
  private $primaryBuffer;
  private $secundaryBuffer;
  private $position;

  private const $BUFFER_SIZE = 4;

  private $file;
  private $finalizou = false;

  private $currentChar;
  private $lastChar;

  public function __construct($file) 
  {
    $this->primaryBuffer = "";
    $this->secondaryBuffer = "";
    $this->position = 0;
    $this->file = $file;
  }

  private function switchBuffers()
  {
    $this->primaryBuffer = $this->secondaryBuffer;

    $this->fillBuffer();
    $this->position = 0;
  }

  public function fillBuffer()
  {
    if ($this->finalizou) {
      $this->secondaryBuffer = "";
      return;
    }

    $this->secondaryBuffer = fread($this->file, $this->BUFFER_SIZE);

    if (strlen($this->secondaryBuffer) < $this->BUFFER_SIZE) {
      $this->finalizou = true;
    }
  }

  public function getNextChar()
  {
    $char = $this->primaryBuffer[$this->position];
    $this->position++;


    if ($this->position == $this->BUFFER_SIZE) {
      $this->switchBuffers();
    }

    return $char;
  }

  public function rewind() {
    $this->position--;
  }
}