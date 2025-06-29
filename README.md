# 🚦 Semáforo com faixa de Pedestre e Temporizador no AVR e Arduino
Este projeto consiste no desenvolvimento de um circuito com programação em AVR para controlar um tráfego (semáforo), a ser instalado em um cruzamento de pedestre com temporizador. O funcionamento é o seguinte:

*Comportaemnto do circuito:*

Intervalo de tempo para o Semáforo de Veículos(sv):
Verde: 42s
Amarelo: 3s
Vermelho: 15s

Semáforo de Pedestre(sp) sincronizado com o de veículos:
Verde (VDS) : Vermelho (VMP)
Amarelo (AS) : Vermelho (VMP)
Vermelho (VMS) : Verde (VDP)

Piscar Vermelho (VMP) 3x antes de mudar em definitivo.

Botão pulsador para antecipar liberação de passagem dos pedestres:
Se faltar mais do que 10s para o acionamento da cor amarela, reduzir para 10s.
Se faltar menos do que 10s para o acionamento da cor amarela, manter o tempo restante

O display de temporização deve exibir a contagem decrescente com o tempo restante para atravessia do pedestre, ou o tempo restante da cor vermelha no semáforo dos veículos.
Em qualquer outra situação, o display não deve mostrar contagem, apenas uma indicação de que está funcionando, não podendo ficar totalmente apagado.

🛠 Tecnologias e Componentes Utilizados:

| Componente            | Modelo                                                                                                                               | Descrição                                                                                                                                     |
| :-------------------- | :----------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------- |
| Microcontrolador      | [AVR - ATMega328P](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf) | Plataforma Arduino Uno como interface                                                                                                         |
| IDE                   | [MPLabX](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)                                                        | Ambiente de Desenvolvimento Integrado - [Instalação](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/ides/x/install-guide/) |
| Compilador            | [XC8](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/xc8)                                                | [Instalação](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/xc8/install/)                                                  |
| Editor de código      | [Visual Studio Code](https://code.visualstudio.com/)                                                                                | [v1.97.2](https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-user)                         |
| Construtor de projeto | [Makefile](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows)                                      | Power Shell<br>`winget install Chocolatey.Chocolatey`<br>`choco install make`                                                                 |
| Gravador do AVR       | [AVRDudess](https://github.com/ZakKemble/AVRDUDESS/releases/tag/v2.18)                                                               | [ZakKemble/AVRDUDESS/v2.18](https://github.com/ZakKemble/AVRDUDESS/releases/download/v2.18/AVRDUDESS-2.18-setup.exe)                          |
| Simulador eletrônico  | [SimulIDE](https://simulide.com/p/downloads/)                                                                                        | Power Shell<br>`winget install SimulIDE.SimulIDE`                                                                                             |
| Versionamento         | [git](https://git-scm.com/downloads)                                                                                                 | Power Shell<br>`winget install --id Git.Git -e --source winget`                                                                               |

Este projeto faz parte de uma atividade acadêmica e tem como objetivo a aplicação prática de conceitos de eletrônica e programação embarcada.

🗺️ Mapa de entradas e saídas:

Semáforo:

| Função  | Dispositivo       | Descrição               | Pino (Arduino Uno) | Pino (ATmega328P) | PORT |
| :------ | :---------------- | :-----------------------| :----------------- | :-----------------|:-----|
| Entrada | Botão             | Botão do pedestre (B)   | A0                 | 23                | PC0  |
| Saída   | LED Verde         | Verde Pedestre    (VDP) | A1                 | 24                | PC1  |
| Saída   | LED Vermelho      | Vermelho Pedestre (VMP) | A2                 | 25                | PC2  |
| Saída   | LED Verde         | Verde Semáforo (VDS)    | A3                 | 26                | PC3  |
| Saída   | LED Amarelo       | Amarelo Semáforo (AS)   | A4                 | 27                | PC4  |
| Saída   | LED Vermelho      | Vermelho Semáforo (VMS) | A5                 | 28                | PC5  |

Display:

| Função  | Dispositivo   | Descrição               | Pino (Arduino Uno) | Pino (ATmega328P) | PORT |
| :------ | :------------ | :-----------------------| :----------------- | :-----------------|:-----|
| Saída   | Pino a        | Segmento "a" do Display | 0                  | 2                 | PD0  |
| Saída   | Pino b        | Segmento "b" do Display | 1                  | 3                 | PD1  |
| Saída   | Pino c        | Segmento "c" do Display | 2                  | 4                 | PD2  |
| Saída   | Pino d        | Segmento "d" do Display | 3                  | 5                 | PD3  |
| Saída   | Pino e        | Segmento "e" do Display | 4                  | 6                 | PD4  |
| Saída   | Pino f        | Segmento "f" do Display | 5                  | 11                | PD5  |
| Saída   | Pino g        | Segmento "g" do Display | 6                  | 12                | PD6  |
| Saída   | Pino p        | Segmento "p" do Display | 7                  | 13                | PD7  |
| Saída   | Comum Unidade | Unidade do Display      | 8                  | 14                | PB0  |
| Saída   | Comum Dezena  | Dezena do Display       | 9                  | 15                | PB1  |


| 🚦 Simulação no SimulIDE: |
|:----------------------------------------------------------------:|
| ![Semaforo-Temporizado](Semaforo-Temporizado.gif)                |
