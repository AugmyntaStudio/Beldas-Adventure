@echo off

for /f "delims== tokens=1,2" %%G in (settings) do set %%G=%%H

:Options
cls
title Options
echo ====================================================
echo Welcome to the Beta Studio Compiler!
echo 1. Compile
echo 2. Debug your compiled application
echo 3. Start your compiled application
echo 4. Settings
echo 5. Credits
echo 6. Quit
echo ====================================================
set /p option=What would you like to do: 

cls

if %option% == 1 (
    goto CompileWarning
)

if %option% == 2 (
    goto Debug
)

if %option% == 3 (
    goto Start
) 

if %option% == 4 (
    goto Settings
)

if %option% == 5 (
    goto Credits
)

if %option% == 6 (
    goto Quit
)

title Error
echo ===========================================================================
echo Sorry that doesn't exist. You can navigate using numbers like 1 or 2.
echo ===========================================================================
pause
goto Options

:CompileWarning
title Warning
set /p accept=Are you sure you want to compile your code (Y/N): 

if %accept% == Y (
    goto Compile
)

if %accept% == N (
    goto Options
)

cls
title Error
echo =========================================================================================
echo That was not a option you could choose from. Please try using Y for yes or N for no.
echo =========================================================================================
pause
cls
goto CompileWarning

:Compile
cls
title Compile
echo Converting .rc file to .o file
windres %TargetDirectory%\info\info.rc %TargetDirectory%\info\info.o
echo .rc file converted succesfully
echo Compiling code...
g++ %TargetDirectory%\info\info.o -g %TargetDirectory%\%TargetFile% %TargetDirectory%\glad.c -o %OutputDirectory%\%OutputName%.%FileExtension% -lglfw3 -lopengl32 -lgdi32 -Wall -I%TargetDirectory% -I%TargetDirectory%\include -static-libgcc -static-libstdc++ -std=c++11
echo Code compiled
echo Zipping files...
tar -caf Beldas_Adventure.zip dist/*
echo Files have been zipped
pause
goto Options

:Debug
cls
title Debug
echo Application Started
cd %OutputDirectory%
gdb %OutputName%.%FileExtension%
echo Exited application
pause
goto Options

:Start
cls
title Start
echo Application Started
cd %OutputDirectory%
%OutputName%.%FileExtension%
echo Exited application
cd..
pause
goto Options

:Settings
cls
title Settings
for /f "delims== tokens=1,2" %%G in (settings) do set %%G=%%H

echo ====================================================
echo The options for what you can do
echo ====================================================
echo 1. Change your current settings
echo 2. See your current settings
echo 3. Go back
echo ====================================================
set /p SettingsOption=What would you like to do: 

if %SettingsOption% == 1 (
    goto ApplySettings
)

if %SettingsOption% == 2 (
    goto CurrentSettings
)

if %SettingsOption% == 3 (
    goto Options
)

cls
title Error
echo ===========================================================================
echo Sorry that doesn't exist. You can navigate using numbers like 1 or 2.
echo ===========================================================================
pause
goto Settings

:CurrentSettings
cls
title CurrentSettings
echo ====================================================
echo These are your current settings:
echo ====================================================
echo Output Directory: %OutputDirectory%
echo Output Name: %OutputName%
echo File Extension: %FileExtension%
echo Target Directory %TargetDirectory%
echo Target File: %TargetFile%
echo ====================================================
pause
goto Settings

:ApplySettings
cls
title Apply Settings
echo ====================================================
echo Settings:
echo 1. Output Directory
echo 2. Output Name
echo 3. Output File Extension
echo 4. Target Directory
echo 5. Target File
echo 6. Go back
echo ====================================================
set /p ApplySettingsOption=What setting would you like to change: 

if %ApplySettingsOption% == 1 (
    goto ChangeSettingOne
)

if %ApplySettingsOption% == 2 (
    goto ChangeSettingTwo
)

if %ApplySettingsOption% == 3 (
    goto ChangeSettingThree
)

if %ApplySettingsOption% == 4 (
    goto ChangeSettingFour
)

if %ApplySettingsOption% == 5 (
    goto ChangeSettingFive
)

if %ApplySettingsOption% == 6 (
    goto Settings
)

cls
title Error
echo ===========================================================================
echo Sorry that doesn't exist. You can navigate using numbers like 1 or 2.
echo ===========================================================================
pause
goto ApplySettings

:ChangeSettingOne
cls
title Adjust Setting One
set /p ChangeSettingOption=What would you like to change it to: 

(
    echo OutputDirectory="%ChangeSettingOption%"
    echo OutputName=%OutputName%
    echo FileExtension=%FileExtension%
    echo TargetDirectory=%TargetDirectory%
    echo TargetFile=%TargetFile%
) >settings
goto Settings

:ChangeSettingTwo
cls
title Adjust Setting Two
set /p ChangeSettingOption=What would you like to change it to: 

(
    echo OutputDirectory=%OutputDirectory%
    echo OutputName=%ChangeSettingOption%
    echo FileExtension=%FileExtension%
    echo TargetDirectory=%TargetDirectory%
    echo TargetFile=%TargetFile%
) >settings
goto Settings

:ChangeSettingThree
cls
title Adjust Setting Three
set /p ChangeSettingOption=What would you like to change it to: 

(
    echo OutputDirectory=%OutputDirectory%
    echo OutputName=%OutputName%
    echo FileExtension=%ChangeSettingOption%
    echo TargetDirectory=%TargetDirectory%
    echo TargetFile=%TargetFile%
) >settings
goto Settings

:ChangeSettingFour
cls
title Adjust Setting Four
set /p ChangeSettingOption=What would you like to change it to: 

(
    echo OutputDirectory=%OutputDirectory%
    echo OutputName=%OutputName%
    echo FileExtension=%FileExtension%
    echo TargetDirectory="%ChangeSettingOption%"
    echo TargetFile=%TargetFile%
) >settings
goto Settings

:ChangeSettingFive
cls
title Adjust Setting Five
set /p ChangeSettingOption=What would you like to change it to: 

(
    echo OutputDirectory=%OutputDirectory%
    echo OutputName=%OutputName%
    echo FileExtension=%FileExtension%
    echo TargetDirectory=%TargetDirectory%
    echo TargetFile=%ChangeSettingOption%
) >settings
goto Settings

:Credits
title Credits
echo ===========================================================================================================                                                                                             
echo                                                                      =B==-                         
echo                                                                    =BBBBBBBBB=-                    
echo                                      ---------           --==BBBBBBBBBBBBBBBBBB==---               
echo                               -==BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB-              
echo                            =BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB==-               
echo                         -=BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB--                       
echo                       -BBBBBB=BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB=-                          
echo                     -BBBBBBB- -BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB-                             
echo                   -BBBBBBB= =B--BBBBBBBBBBB===BBBBBBBBBBBBBBBBBBBB=                                
echo                 -BBBBBBB= -BBBB==BBBBBBBBB-       ---=======BBBBBBB-                               
echo               -BBBBBB=-   BBBBB==BBBBBBB=-            BB==B= =BBBBBB-                              
echo              =BBB=-       BBB---BBBBBB=-             -BBBBB   -BBBBBB=                             
echo                          BBB-  -BBBBBB-              =BBBB-     -BBBBB=                            
echo                         =BB=     -BBBBB=             BBBB-        =BBBB=                           
echo                        BBBB        -BBBBB-           BBBB          -BBBB=                          
echo                        BBB=          -BBBBBBB=       BBBBBB=         -BBBBBB=-                     
echo                         -              -------        ------           -------                     
echo ===========================================================================================================                                                                                                    
echo                                   This compiler interface has been made by Beta Studio.
pause
goto Options

:Quit
cd..
cd..
cd..
title Command Prompt