
           Como añadir al proyecto soporte automático para tests.
          ========================================================

1.  Copiar los ficheros en las carpetas correctas.

        Colocamos en la carpeta donde se invoca a CMake (carpeta donde se 
        construye el software) el siguiente fichero:

        - Fichero CTestCustom.cmake (contiene las personalizaciones realizadas
          sobre CTest).

2.  Nos situamos en la carpeta donde se construye el software e invocamos a
    CMake.

    $ ccmake ../../src

3.  Una vez invocado a CMake, ejecutamos CTest para verificar que los cambios
    se han realizado correctamente.

    $ ctest
    Test project /release-2.0.4/build/amilab
        Start 1: test_levelsets
    1/9 Test #1: test_levelsets ...................   Passed    7.97 sec
        Start 2: test_readwrite_vtk
    2/9 Test #2: test_readwrite_vtk ...............   Passed    0.77 sec
        Start 3: test_readwrite_mhd
    3/9 Test #3: test_readwrite_mhd ...............   Passed    0.75 sec
        Start 4: test_readwrite_ami
    4/9 Test #4: test_readwrite_ami ...............   Passed    0.72 sec
        Start 5: test_readwrite_ami.gz
    5/9 Test #5: test_readwrite_ami.gz ............   Passed    0.72 sec
        Start 6: test_readwrite_picture_png
    6/9 Test #6: test_readwrite_picture_png .......   Passed    0.75 sec
        Start 7: test_readwrite_picture_jpg
    7/9 Test #7: test_readwrite_picture_jpg .......   Passed    0.78 sec
        Start 8: test_readwrite_picture_tiff
    8/9 Test #8: test_readwrite_picture_tiff ......   Passed    0.75 sec
        Start 9: test_readwrite_picture_bmp
    9/9 Test #9: test_readwrite_picture_bmp .......   Passed    0.84 sec

    100% tests passed, 0 tests failed out of 9

    Total Test time (real) =  14.05 sec

4.  A continuación, elaboramos un script para que ejecute CTest con las
    opciones necesarias para que genere y envié una nueva entrada en CDash.

    #!/bin/sh
    #Nos situamos en la carpeta donde se construyo el software.
    cd /home/fsantana/proyectos/amilab/release-2.0.4/build/amilab

    #Exportamos la variable AMI_SCRIPTS.
    export AMI_SCRIPTS=/home/fsantana/proyectos/amilab/release-2.0.4/scripts

    #Invocamos a ctests con la opción -D y el parámetro Nightly.
    xinit /usr/bin/xterm -title "Ejecutando CTest." -e bash -c "ctest -D Nightly" -- :1

5.  Programamos el demonio cron para que lance el anterior script en el momento
    que deseemos. Para ello usamos el crontab.

    $ crontab -l
    # Minute   Hour   Day of Month       Month          Day of Week        Command    
    # (0-59)  (0-23)     (1-31)    (1-12 or Jan-Dec)  (0-6 or Sun-Sat)  
        01      02         *              *                 *              ctest_amilab.sh
