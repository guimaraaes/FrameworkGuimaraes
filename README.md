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

### 4. Adicionando o Framework Guimarães ao Seu Projeto
Após configurar a estrutura básica do seu projeto Arduino com PlatformIO, você pode querer adicionar bibliotecas ou frameworks externos, como o framework Guimarães. Aqui estão os passos para adicionar o código do framework Guimarães ao diretório `lib/` do seu projeto:
 - **Clone via Git**: Se você estiver familiarizado com o Git, pode clonar o repositório diretamente para o diretório `lib/` do seu projeto PlatformIO usando o comando:
   ```
   git clone https://github.com/guimaraaes/framework-guimaraes.git lib/FrameworkGuimaraes
   ```
 - **ou Download Manual**: Alternativamente, você pode baixar o repositório como um arquivo ZIP e extrair o conteúdo manualmente na pasta `lib/FrameworkGuimaraes` dentro do diretório do seu projeto PlatformIO.

### 5. Desenvolva Seu Código
Com o ambiente configurado, você pode começar a desenvolver seu código Arduino no diretório `src/`.
   - No seu código-fonte (`src/`) inclua os cabeçalhos ou use as funcionalidades do framework Guimarães e outras bibliotecas que for utilizar.

### 6. Compile e Carregue
- **Compile o Projeto**: No PlatformIO IDE, use a opção de compilação (geralmente um ícone de 'check' na barra inferior) para verificar se não há erros em seu código.
- **Carregue no Arduino**: Com o Arduino conectado ao seu computador, use a opção de upload (geralmente um ícone de 'seta para cima') para carregar seu código para a placa Arduino.

### 7. Monitore e Depure
- **Monitor Serial**: Para ver a saída do seu Arduino, use o Monitor Serial do PlatformIO.
- **Depuração**: Se o seu projeto e placa suportarem, você pode usar recursos de depuração integrados para solucionar problemas em seu código.
 
