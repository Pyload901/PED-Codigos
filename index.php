<?php
    class miObj {
        public $summary;
        public $date;
        function __construct($summary, $date) {
            $this->summary = $summary;
            $this->date = $date;
        }
    };

    $mi_array_asociativo = [
        'elemento' => 'valor',
        'otro_elemento' => 'Otro valor',
        'cualquier_cosa' => true,
    ];
    $mi_objeto = json_decode(json_encode($mi_array_asociativo));
    // $obj = new miObj('Hola', getdate());

    // array_push(arr, $obj);
    // ...
    // $arr -> stdObj(['summary']->'fjdsajflds', ...)

    print_r($mi_objeto);
    echo $mi_objeto->elemento;
?>