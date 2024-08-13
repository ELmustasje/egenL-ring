from flask import Flask, render_template, request, url_for, flash, redirect

from db import *


app = Flask(__name__)


@app.route('/',methods=('GET','POST'))
def index():
    if request.method == 'POST':
        button = request.form.get("submit")
    return render_template("index.html",bikes=getbikes())

if __name__ == "__main__":  
    app.run(debug=True)  