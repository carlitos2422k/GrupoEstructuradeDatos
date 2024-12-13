cmake_minimum_required(VERSION 3.10)

# Define el nombre de tu proyecto
project(ValidacionesTests)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Incluir directorios relevantes
include_directories(${CMAKE_SOURCE_DIR})

# Configurar las rutas de Google Test
set(GTEST_INCLUDE_DIR "C:/Users/Carlos/Desktop/GrupoEstructuradeDatos/Codigo/googletest/googletest/include")
set(GTEST_LIB_DIR "C:/Users/Carlos/Desktop/GrupoEstructuradeDatos/Codigo/googletest/lib") # Asegúrate de tener la biblioteca aquí si la compilas por separado

include_directories(${GTEST_INCLUDE_DIR})
link_directories(${GTEST_LIB_DIR})

# Crear los archivos fuente para el programa principal
set(SOURCE_FILES 
    utils.h
    Validaciones.h
)

# Crear ejecutable principal
add_executable(main main.cpp ${SOURCE_FILES})

# Crear ejecutable para pruebas unitarias
add_executable(ProgramaTest main_test.cpp ${SOURCE_FILES})
target_link_libraries(ProgramaTest PRIVATE ${GTEST_LIB_DIR}/libgtest.a pthread)

# Configurar las pruebas
enable_testing()
add_test(NAME ProgramaTest COMMAND ProgramaTest)
