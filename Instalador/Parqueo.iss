[Setup]
AppName=MiPrograma
AppVersion=1.0
DefaultDirName={userdesktop}\MiPrograma
DefaultGroupName=MiPrograma
OutputBaseFilename=MiProgramaInstaller
Compression=lzma
SolidCompression=yes

[Files]
; Ruta al ejecutable main.exe
Source: "C:\Users\Carlos\Desktop\GrupoEstructuradeDatos - copia\main.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
; Crear acceso directo en el menú de inicio
Name: "{group}\MiPrograma"; Filename: "{app}\main.exe"

[Code]
var
  InputPage: TInputQueryWizardPage;
  UserKey: String;

procedure InitializeWizard();
begin
  // Crear una página personalizada para capturar la clave de instalación
  InputPage := CreateInputQueryPage(wpWelcome, 
    'Clave de Instalación', 
    'Introduce tu clave de instalación para continuar', 
    'Ingresa la clave de instalación en el campo de texto a continuación:');
  InputPage.Add('Clave de Instalación:', False);

  // Mostrar la página y capturar la entrada del usuario
end;

function NextButtonClick(CurPageID: Integer): Boolean;
begin
  Result := True;

  // Validar la clave solo si estamos en la página personalizada
  if CurPageID = InputPage.ID then
  begin
    UserKey := InputPage.Values[0];

    if UserKey = '' then
    begin
      MsgBox('Debes ingresar una clave para continuar.', mbError, MB_OK);
      Result := False; // Evita que el usuario avance
    end
    else if UserKey <> 'ABC12-ASD12-TPOP8-POPA9-89ASD' then
    begin
      MsgBox('Clave inválida. Instalación cancelada.', mbError, MB_OK);
      Result := False; // Evita que el usuario avance
    end;
  end;
end;
