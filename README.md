Recurso de autocompletar

A função de auto-completar é extremamente comum em aplicações modernas. À medida que o usuário digita, o programa prevê a consulta completa (normalmente uma palavra ou frase) que o usuário pretende digitar. O preenchimento automático é mais eficaz quando há um número limitado de consultas prováveis. Por exemplo, o [Internet Movie Database](https://www.imdb.com/) o utiliza para exibir os nomes dos filmes conforme o usuário digita; os mecanismos de pesquisa o utilizam para exibir sugestões conforme o usuário insere consultas de pesquisa na _web_; os telefones celulares o utilizam para agilizar o processo de entrada de texto.

Veja abaixo os exemplos citados:

![alt text](image.png)

Nestes exemplos, a aplicação prevê a probabilidade de o usuário digitar cada consulta e apresenta ao usuário uma lista das principais consultas correspondentes, em ordem decrescente de peso. Esses pesos são determinados por dados históricos, como receitas de bilheteria de filmes, frequências de consultas de pesquisa de outros usuários do Google ou histórico de digitação de um usuário de telefone celular. Para efeitos desta atribuição, você terá acesso a um conjunto de todas as termos possíveis e pesos associados (e essas consultas e pesos não serão alterados).

O desempenho da funcionalidade de preenchimento automático é fundamental em muitos sistemas. Por exemplo, considere um mecanismo de pesquisa que executa um aplicativo de preenchimento automático em um _datacenter_. Para que o usuário tenha uma boa experiência ao usar a aplicação, ela deve retornar as sugestões em cerca de 50ms! Além disso, em princípio, essa função deve realizar esse cálculo para cada pressionamento de tecla digitado na barra de pesquisa e para cada usuário!

Nesta tarefa, você implementará o preenchimento automático ordenando todos os termos possíveis de consulta; irá utilizar pesquisa binária para encontrar todas as correspondências que começam com um determinado prefixo; e por fim ordenando os termos correspondentes por peso.


## Execução do programa

Quando você executar o programa, ele irá receber como parâmetros posicionais o *dataset* desejado e um valor inteiro `k`. Esse valor inteiro limita a quantidade de retorno de termos do recurso de autocompletar para `k` termos caso ele retorne um valor maior ou igual a `k`.

O programa, então permite que o usuário entre com a consulta desejada, e então apertar `<ENTER>` para realizar a etapa de preenchimento automático. O programa retorna os `k` termos que casaram com o prefixo informado, ordenado por peso. Ele pode repetir o processo quantas vezes quiser, até que seja enviado a palavra `sair`, que encerra a execução do programa. Veja um exemplo de execução e interação com o programa:

```bash
$ ./bin/autocompletar datasets/actors.txt 10

Entre com o termo a ser auto-completado: (digite "sair" para encerrar o programa): 
Will <ENTER>
2790243210      Will Smith (I)
2739685985      Willem Dafoe
2402502653      William Fichtner
2178370600      Will Ferrell
1737902013      Will Arnett
1674790786      William H. Macy
1589682687      William Melling
1398831928      William Hurt
1172371613      William Shatner
1132672375      William Sadler (I)

Entre com o termo a ser auto-completado: (digite "sair" para encerrar o programa): 
Mary <ENTER>
1811632876      Mary Ellen Trainor
1322246171      Mary Steenburgen
1095979260      Mary Pat Gleason
923434547       Mary Kay Place
805518471       Mary Kay Bergman
751856240       Mary Linda Phillips
666922752       Mary Lynn Rajskub
662564172       Mary Black (I)
655198435       Mary McDonnell (I)
617010839       Mary-Louise Parker

Entre com o termo a ser auto-completado: (digite "sair" para encerrar o programa): 
sair <ENTER>

$ 
```
