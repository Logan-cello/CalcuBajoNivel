include 'win32ax.inc'
include 'controles.inc'

.data

ClassName db 'CalculadoraFASM',0
AppName   db 'Ventana 1',0

EditClass   db 'EDIT',0
ButtonClass db 'BUTTON',0

Vacio db '',0

txtAC    db 'AC',0
txtBack  db '<-',0
txtPorc  db '%',0
txtDiv   db '/',0

txt7     db '7',0
txt8     db '8',0
txt9     db '9',0
txtMul   db 'X',0

txt4     db '4',0
txt5     db '5',0
txt6     db '6',0
txtSub   db '-',0

txt1     db '1',0
txt2     db '2',0
txt3     db '3',0
txtAdd   db '+',0

txt0     db '0',0
txtComa  db ',',0
txtPunto db '.',0
txtIgual db '=',0

txtSalir db 'Salir',0

hInstance dd ?
hWnd      dd ?
hEditOp   dd ?
hEditRes  dd ?

wc  WNDCLASS
msg MSG

buffer  rb 128
btnText rb 16


.code

start:

    invoke GetModuleHandle,0
    mov [hInstance],eax

    mov [wc.style],CS_HREDRAW or CS_VREDRAW
    mov [wc.lpfnWndProc],WndProc
    mov [wc.cbClsExtra],0
    mov [wc.cbWndExtra],0

    mov eax,[hInstance]
    mov [wc.hInstance],eax

    invoke LoadIcon,0,IDI_APPLICATION
    mov [wc.hIcon],eax

    invoke LoadCursor,0,IDC_ARROW
    mov [wc.hCursor],eax

    mov [wc.hbrBackground],COLOR_BTNFACE+1
    mov [wc.lpszMenuName],0
    mov [wc.lpszClassName],ClassName

    invoke RegisterClass,wc

    invoke CreateWindowEx,\
        0,\
        ClassName,\
        AppName,\
        WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_MINIMIZEBOX,\
        CW_USEDEFAULT,\
        CW_USEDEFAULT,\
        250,\
        360,\
        0,\
        0,\
        [hInstance],\
        0

    mov [hWnd],eax

    invoke ShowWindow,[hWnd],SW_SHOWNORMAL
    invoke UpdateWindow,[hWnd]


mensaje:

    invoke GetMessage,msg,0,0,0

    cmp eax,1
    jb salir

    invoke TranslateMessage,msg
    invoke DispatchMessage,msg

    jmp mensaje


salir:

    invoke ExitProcess,[msg.wParam]


proc WndProc hwnd,wmsg,wparam,lparam

    cmp [wmsg],WM_CREATE
    je .crear

    cmp [wmsg],WM_COMMAND
    je .comando

    cmp [wmsg],WM_DESTROY
    je .destruir


    invoke DefWindowProc,[hwnd],[wmsg],[wparam],[lparam]
    ret


.crear:

    stdcall CrearControles,[hwnd]

    xor eax,eax
    ret


.comando:

    stdcall ProcesarComando,[hwnd],[wparam],[lparam]

    xor eax,eax
    ret


.destruir:

    invoke PostQuitMessage,0

    xor eax,eax
    ret

endp


include 'ventana.inc'
include 'eventos.inc'
include 'operadores.inc'


.end start