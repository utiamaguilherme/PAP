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
def hello():
    return hmtl_template("hahaha")

@app.route('/oi')
def oi():
    return html_template("OOi")

# @app.route('/getRegisters')
# def getRegisters():
#     return html_template("retorna todos os registros do aluno, etc")


# @app.route('/accessed')
# def accessed():

#
# @app.route('/ou/index')
# def idx():
#     return html_template("retorna pagina hthml que existe a lista de registros e a quantidade de acessos")


@app.route('/user/<username>', method=['GET', 'POST'])
def say_hello(username):
    if request.method == 'POST':
        return 'Olá usuário {}. Idade {}.'.format(username, request.form['idade'])
    else:
        return 'Olá usuário {}. Idade{}.'.format(username, request.args.get('idade', ''))
