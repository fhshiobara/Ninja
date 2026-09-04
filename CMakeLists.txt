cmake_minimum_required(VERSION 3.16)

# ============================================================
# Nome do Novo Projeto: Ninja
# ============================================================
project(Ninja LANGUAGES CXX)

set(EXECUTAVEL ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# SFML (Configurado para o seu Mac via Homebrew)
# ============================================================
set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")

find_package(SFML 2.6 REQUIRED COMPONENTS
    graphics
    window
    system
    audio
)

include_directories(include)

# ============================================================
# Copia a pasta assets para a pasta de build
# ============================================================
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# ============================================================
# Headers (.h / .hpp) — 100% automático
# Basta criar o arquivo dentro de "include/" (ou em subpastas,
# ex: include/entidades/Jogador.hpp) que ele é pego sozinho,
# sem precisar editar este CMakeLists.
# ============================================================
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS
    "include/*.h"
    "include/*.hpp"
)

# ============================================================
# Assets (apenas para aparecerem na IDE)
# ============================================================
file(GLOB_RECURSE ASSET_FILES CONFIGURE_DEPENDS
    "assets/*"
)

# ============================================================
# Arquivos fonte (.cpp)
# Diferente dos headers, os .cpp PRECISAM ser listados aqui.
# (O CMake não detecta .cpp novos sozinho — só reconfigurando.)
# ============================================================
set(SOURCES
    src/main.cpp
    src/GerenciadorGrafico.cpp
    src/Ente.cpp
    src/Entidade.cpp
    src/Animation.cpp
    src/Personagem.cpp
    src/Inimigo.cpp
    src/Jogador.cpp
    
    
    
    

    # ------------------------------------------------------
    # >>> ADICIONE SEUS NOVOS ARQUIVOS .cpp AQUI EMBAIXO <<<
    # Ex:
    # src/Jogador.cpp
    # src/Inimigo.cpp
    # src/Fase.cpp
    # ------------------------------------------------------
)

# ============================================================
# Criação do executável
# ============================================================
add_executable(${EXECUTAVEL}
    ${SOURCES}
    ${HEADER_FILES}
    ${ASSET_FILES}
)

# Garante que o Xcode use a pasta build como diretório de trabalho para achar os assets
if(APPLE)
    set_target_properties(${EXECUTAVEL} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        XCODE_ATTRIBUTE_CUSTOM_LAUNCH_PROPERTY "${CMAKE_BINARY_DIR}"
    )
endif()

# ============================================================
# Organiza as pastas na IDE (Xcode)
# ============================================================
source_group(
    TREE "${CMAKE_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_FILES}
)

source_group(
    TREE "${CMAKE_SOURCE_DIR}/assets"
    PREFIX "Assets"
    FILES ${ASSET_FILES}
)

# ============================================================
# Bibliotecas (Linkando a SFML ao Ninja)
# ============================================================
target_link_libraries(${EXECUTAVEL}
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)
