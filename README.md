# English

The Quan project is a blockchain experiment.

## Binaries

You can download the binaries for Linux, MacOS, and Windows [HERE](https://github.com/)

## Building Quan 

### On *nix and OSX

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.58.

You may download them from:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/
* Alternatively, it may be possible to install them using a package manager.

To build, go the the project folder - same level of src - and run:
```
mkdir build
cd build
cmake ..
make
```

The resulting executables can be found in `build/src`.

**Advanced options:**

* Parallel build: run `make -j<number of threads>` instead of `make`.
* Debug build: run `make build-debug`.
* Test suite: run `make test-release` to run tests in addition to building. Running `make test-debug` will do the same to the debug version.
* Building with Clang: it may be possible to use Clang instead of GCC, but this may not work everywhere. To build, run `export CC=clang CXX=clang++` before running `make`.

### On Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55. You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run theas commands: 
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```

# Português
Quan é um projeto de blockchain de código aberto.

## Binários

Você pode realizar o download dos Binários para Linux, MacOS, e Windows [AQUI](https://github.com/)

## Compilando Quan

### Em *nix e OSX

Dependências: GCC 4.7.3 ou superior, CMake 2.8.6 ou superior e Boost 1.58.

Você pode baixá-las em:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/
* Como alternativa, pode ser possível instalá-las usando um gerenciador de pacotes.

Para compilar, vá a pasta do projeto - mesmo diretório de src - e execute:
```
mkdir build
cd build
cmake ..
make
```

Os executáveis resultantes podem ser encontrados em `build/src`.

**Opções Avançadas:**

* Compilação paralela: execute `make -j<number of threads>` em vez de `make`.
* Compilação debug: execute `make build-debug`.
* Test suite: execute `make test-release` para executar testes além da compilação. Executando `make test-debug` fará o mesmo com a versão de depuração.
* Compilando com Clang: pode ser possível usar Clang ao invés de GCC, mas isso pode não funcionar em todos os lugares. Para compilar, execute `export CC=clang CXX=clang++` antes de executar `make`.

### No Windows
Dependências: MSVC 2013 ou superior, CMake 2.8.6 ou superior e Boost 1.55. 

Você pode baixá-las em:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

Para compilar, vá ao diretório onde este arquivo está e execute os seguintes comandos:
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```
