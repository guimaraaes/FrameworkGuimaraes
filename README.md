## Guia para configuração de projeto

### 1. Instale o PlatformIO
PlatformIO é um ecossistema de código aberto para desenvolvimento IoT. Aqui ele é usado como um plugin no VSCode.
  -  Instale o Visual Studio Code (VS Code) e depois instale a extensão PlatformIO IDE diretamente do marketplace do VS Code.

### 2. Configure o PlatformIO
Após a instalação, configure o PlatformIO para seu projeto Arduino específico.

- **Crie um Novo Projeto**: No VS Code com PlatformIO IDE, você pode criar um novo projeto via `PlatformIO Home > New Project`. Especifique o nome do projeto, o tipo de placa (Arduino Uno), e o framework Arduino.
- **Adicione Bibliotecas Necessárias**: Se seu projeto requer bibliotecas específicas, adicione-as através do `PlatformIO Home > Libraries` ou diretamente no arquivo `platformio.ini` do seu projeto.

### 3. Explore a Estrutura do Projeto
Um projeto PlatformIO tem uma estrutura de diretório padrão:
- **src/**: Diretório onde você coloca seu código-fonte (por exemplo, arquivos `.ino` ou `.cpp`).
- **lib/**: Diretório para bibliotecas personalizadas.
- **test/**: Para testes automatizados (se aplicável).
- **platformio.ini**: Arquivo de configuração do projeto, onde você especifica configurações como placa, framework, bibliotecas, etc.

### 4. Adicionando o Framework Guimarães e Arduino Unit ao Seu Projeto
Após configurar a estrutura básica do seu projeto Arduino com PlatformIO, você pode querer adicionar bibliotecas ou frameworks externos, como o framework Guimarães. Aqui estão os passos para adicionar o código do framework Guimarães ao diretório `lib/` do seu projeto:
 - **Clone via Git**: Se você estiver familiarizado com o Git, pode clonar o repositório diretamente para o diretório `/` do seu projeto PlatformIO usando o comando:
   ```
   git clone https://github.com/guimaraaes/FrameworkGuimaraes.git FrameworkGuimaraes
   ```
   e para o diretório `lib/` do seu projeto PlatformIO usando o comando:
   ```
   git clone https://github.com/mmurdoch/arduinounit.git lib/ArduinoUnit
   ```
   
 - **ou Download Manual**: Alternativamente, você pode baixar o repositório como um arquivo ZIP e extrair o conteúdo manualmente nas respectivas pastas da clonagem.


### 5. Teste a instação com o código Blink no código-fonte
Com o ambiente configurado, você pode testar a configuração inserindo o código Blink abaixo em `src/main.cpp`.

```
#include <Arduino.h>
#include "../FrameworkGuimaraes/FrameworkGuimaraes.h"

ActuatorDigital *light;

void setup()
{
  // put your setup code here, to run once:
  CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
  light = creatorActuatorDigital->createComponent(13);
}

void loop()
{
  // put your main code here, to run repeatedly:
  light->write(HIGH);
  delay(1000);

  light->write(LOW);
  delay(1000);
}
```

