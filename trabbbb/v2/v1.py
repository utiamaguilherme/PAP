from flask import Flask
from flask import request

app = Flask(__name__)

users = [[],[],[]]


def html_template (msg):
    html = """<html>
                <body>
                <h1>Hello</h1>
                <p1>{}</p1>
                <form action="/" method="post">
                    idade:
                    <input type="text" placeholder="Digite aqui"> <br/>
                </form>
                </body>
                </html>""".format(msg)
    return html


def sucesso (msg):
    html = """<html>
                <body>
                <h1>Sucesso</h1
                <form action = "/acesso" method = "get">
                {}
                </body>
                </html>""".format(msg)
    return html


def html_init(msg):
    html = """<html>
                <body>
                <h1>Cadastro</h1>
                <p1>{}</p1>
                <form action="/acesso" method="post">
                    id:
                    <input type = "text", placeholder="Digite aqui"><br>
                    cpf:
                    <input type = "text", placeholder="Digite aqui"><br>
                    nome:
                    <input type = "text", placeholder="Digite aqui"><br>
                    <div class="button">
                    <button type="submit">Enviar sua mensagem</button>
                    </div>
                </form>
                </body>
                </html>""".format(msg)
    return html

def mostra(users):
    listUsers = ''
    for user in users:
        listUsers+=(user+'\n')
    return sucesso(listUsers)


@app.route('/')
def foi():
    return html_init("BEM-VINDO")


@app.route('/acesso')
def init():
    return sucesso("BEM-VINDO")



@app.route('/getRegisters')
def get():
    return html_template("oi")
    # return list com todos os registros de todos os usuarios

# @app.route('/accessed')
# def acesso(lista dos ids que acessaram a catraca):
    # sem retorno

@app.route('/ou/index')
def idx():
    return html_template("pagina html que existe a lista de registro e a qtd de acessos")

@app.route('/user/<username>', methods=['GET', 'POST'])
def say_hello(username):
    if request.method == 'POST':
        return 'Olá usuário {}. Idade {}.'.format(username, request.form['idade'])
    else:
        return 'Olá usuário {}. Idade{}.'.format(username, request.args.get('idade', ''))
