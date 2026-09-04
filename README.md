# Ninja

Coisas que são importantes de lembrar:
0.1- O tamanho da tela que está sendo projetada é de 1920:1080
0.2- As coordenadas em Y são dadas de cabeça para baixo, o 0 é no topo da tela
0.3- Tabela de IDs:
	Jogador: 1
	 



A ideia vai ser a seguinte:

1- Tudo que EXISTE será uma ENTE, por isso terá um id que eu escolherei por classes por exemplo, o jogador será o id=1, os inimigos fáceis serão o id=2 e assim por diante, colocarei nesse arquivo o id de cada coisa para organizar melhor. O objetivo disso é facilitar possíveis processos no futuro, como por exemplo o gerenciador de colisão onde posso apenas checar uma colisão entre entidades de um certo id para fazer o efeito.
1.1- Como tudo que EXISTE está englobado nessa classe, é válido deixar como atributo base um PONTEIRO PARA UMA HITBOX E/OU ÁREA DE CONTATO onde será renderizados o Sprite
1.2- Vou adicionar aqui um local para definir o tamanho da hitbox de cada bicho, para que a hitbos tenha algum tamanho que possa ser redefinido depois, caso necessário.

2- Tudo que se move, será uma ENTIDADE portanto essa classe terá dois vetores, um para posição e outro para a velocidade. Não colocarei vida nesse ponto pois posso fazer um obstaculo ou projeteis que inevitavelmente nao vou querer que morram, para atormentar o jogador
2.1- Como os obstáculos irão ser derivados dessa classe, vou zerar a velocidade deles. Apenas mudando caso haja a necessidade.
2.2- Estou implementando o mover aqui de forma totalmente linear, ou seja, estou simplesmente adicionando à posição o valor que está contido na velocidade, não sei se isso terá alguma implicação negativa no futuro.
2.3- Vou colocar como um atributo de ENTIDADE uma ANIMATION própria de cada um. Como ela vai derivar PERSONAGEM e OBTÁCULOS, coisas que eu planejo que tenham textura, vou adiantar o atributo aqui.



3- PERSONAGEM ainda vai ser uma classe abstrata. Tudo que TEM PONTOS DE VIDA será um personagem, como graças à classe ENTIDADE, que a atual é filha já da os atributos de velocidade e de posição, a classe PERSONAGEM, por ora, só deve controlar se está vivo e o número de vidas.

3.1- Os atributos NOCHAO e OLHANDOESQUERDA vão servir para o controle e implementação de funções futuras além de ajudarem no controle de sprites. 




