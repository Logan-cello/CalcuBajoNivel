proc ProcesarComando uses ebx esi edi, hwnd,wparam,lparam

    mov eax,[wparam]
    and eax,0FFFFh


    ; --------------------
    ; SALIR
    ; --------------------

    cmp eax,IDC_BTN_SALIR
    je .salir


    ; --------------------
    ; AC
    ; --------------------

    cmp eax,IDC_BTN_AC
    je .limpiar


    ; --------------------
    ; BORRAR
    ; --------------------

    cmp eax,IDC_BTN_BACK
    je .borrar


    ; ignorar mensajes de los EDIT
    cmp eax,IDC_BTN_PORC
    jb .fin

    cmp eax,IDC_BTN_IGUAL
    ja .fin


    ; leer lo que ya esta escrito
    invoke GetWindowText,[hEditOp],buffer,127

    mov ebx,eax


    ; leer texto del boton
    invoke GetWindowText,[lparam],btnText,15

    mov edx,eax

    ; Reservar espacio para el terminador del buffer.
    add eax,ebx
    cmp eax,127
    ja .fin


    ; buscar final de buffer
    lea edi,[buffer]
    add edi,ebx

    lea esi,[btnText]

    mov ecx,edx


.copiar:

    cmp ecx,0
    je .terminar

    mov al,[esi]
    mov [edi],al

    inc esi
    inc edi

    dec ecx

    jmp .copiar


.terminar:

    mov byte [edi],0

    invoke SetWindowText,[hEditOp],buffer

    jmp .fin


.limpiar:

    invoke SetWindowText,[hEditOp],Vacio
    invoke SetWindowText,[hEditRes],Vacio

    jmp .fin


.borrar:

    invoke GetWindowText,[hEditOp],buffer,127

    cmp eax,0
    je .fin

    lea edi,[buffer]

    add edi,eax

    dec edi

    mov byte [edi],0

    invoke SetWindowText,[hEditOp],buffer

    jmp .fin


.salir:

    invoke SendMessage,[hwnd],WM_CLOSE,0,0


.fin:

    ret

endp