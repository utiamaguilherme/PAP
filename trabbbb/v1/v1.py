from flask import Flask
from flask import request

app = Flask(__name__)

def html_template (msg):
    html = """<html>
                <body>
                <h1>Hello</h1>
                <p1>{}</p1>
                <form action="/user/Utindel" method="post"
                    idade:
                    <input type = "text", name = "text", value = ""><br>
                </form>
                </body>
                </html>""".format(msg)
    return html

@app.route('/')
def init():
    return html_template("BEM-VINDO")

@app.route('/getRegisters')
def get():
    # return list com todos os registros de todos os usuarios

@app.route('/accessed')
def acesso(lista dos ids que acessaram a catraca):
    # sem retorno

@app.route('/ou/index')
def idx():
    return html_template("pagina html que existe a lista de registro e a qtd de acessos")

@app.route('/user/<username>', method=['GET', 'POST'])
def say_hello(username):
    if request.method == 'POST':
        return 'Olá usuário {}. Idade {}.'.format(username, request.form['idade'])
    else:
        return 'Olá usuário {}. Idade{}.'.format(username, request.args.get('idade', ''))
