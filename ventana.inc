proc CrearControles hwnd

    ; cuadro izquierdo
    invoke CreateWindowEx,\
        WS_EX_CLIENTEDGE,\
        EditClass,\
        Vacio,\
        WS_CHILD or WS_VISIBLE or ES_AUTOHSCROLL,\
        20,20,95,25,\
        [hwnd],\
        IDC_EDIT_OP,\
        [hInstance],\
        0

    mov [hEditOp],eax


    ; cuadro derecho
    invoke CreateWindowEx,\
        WS_EX_CLIENTEDGE,\
        EditClass,\
        Vacio,\
        WS_CHILD or WS_VISIBLE or ES_RIGHT or ES_READONLY,\
        125,20,85,25,\
        [hwnd],\
        IDC_EDIT_RES,\
        [hInstance],\
        0

    mov [hEditRes],eax


    ; --------------------
    ; FILA 1
    ; --------------------

    invoke CreateWindowEx,0,ButtonClass,txtAC,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,20,65,45,30,[hwnd],IDC_BTN_AC,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtBack,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,70,65,45,30,[hwnd],IDC_BTN_BACK,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtPorc,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,120,65,45,30,[hwnd],IDC_BTN_PORC,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtDiv,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,170,65,45,30,[hwnd],IDC_BTN_DIV,[hInstance],0


    ; --------------------
    ; FILA 2
    ; --------------------

    invoke CreateWindowEx,0,ButtonClass,txt7,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,20,100,45,30,[hwnd],IDC_BTN_7,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txt8,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,70,100,45,30,[hwnd],IDC_BTN_8,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txt9,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,120,100,45,30,[hwnd],IDC_BTN_9,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtMul,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,170,100,45,30,[hwnd],IDC_BTN_MUL,[hInstance],0


    ; --------------------
    ; FILA 3
    ; --------------------

    invoke CreateWindowEx,0,ButtonClass,txt4,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,20,135,45,30,[hwnd],IDC_BTN_4,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txt5,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,70,135,45,30,[hwnd],IDC_BTN_5,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txt6,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,120,135,45,30,[hwnd],IDC_BTN_6,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtSub,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,170,135,45,30,[hwnd],IDC_BTN_SUB,[hInstance],0


    ; --------------------
    ; FILA 4
    ; --------------------

    invoke CreateWindowEx,0,ButtonClass,txt1,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,20,170,45,30,[hwnd],IDC_BTN_1,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txt2,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,70,170,45,30,[hwnd],IDC_BTN_2,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txt3,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,120,170,45,30,[hwnd],IDC_BTN_3,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtAdd,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,170,170,45,30,[hwnd],IDC_BTN_ADD,[hInstance],0


    ; --------------------
    ; FILA 5
    ; --------------------

    invoke CreateWindowEx,0,ButtonClass,txt0,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,20,205,45,30,[hwnd],IDC_BTN_0,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtComa,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,70,205,45,30,[hwnd],IDC_BTN_COMA,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtPunto,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,120,205,45,30,[hwnd],IDC_BTN_PUNTO,[hInstance],0

    invoke CreateWindowEx,0,ButtonClass,txtIgual,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,170,205,45,30,[hwnd],IDC_BTN_IGUAL,[hInstance],0


    ; --------------------
    ; SALIR
    ; --------------------

    invoke CreateWindowEx,0,ButtonClass,txtSalir,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,75,265,85,30,[hwnd],IDC_BTN_SALIR,[hInstance],0


    ret

endp