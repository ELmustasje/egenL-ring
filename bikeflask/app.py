# Store this code in 'app.py' file

from flask import Flask, render_template, request, redirect, url_for, session
import re
import mysql.connector


app = Flask(__name__)

conn = mysql.connector.connect(
    host="localhost",
    user="root",
    port="3306",
    password="TB-bt1a@",
    database="bikebrothers"
)


@app.route('/',methods =['GET', 'POST'])
def index():
	if request.method == 'POST' and request.form.get('submit') is not None:
		print("POST")
	return render_template('index.html')

@app.route('/storage')
def storage():
	cursor = conn.cursor()
	cursor.execute("SELECT * FROM bike_status WHERE status='storage'")
	bikes = cursor.fetchall()
	return render_template('storage.html',bikes=bikes)

@app.route('/workshop')
def workshop():
	cursor = conn.cursor()
	cursor.execute("SELECT * FROM bike_status WHERE status='workshop'")
	bikes = cursor.fetchall()
	return render_template('workshop.html',bikes=bikes)
	
@app.route('/archive')
def archive():
	cursor = conn.cursor()
	cursor.execute("SELECT * FROM bike_status WHERE status='archive'")
	bikes = cursor.fetchall()
	return render_template('archive.html',bikes=bikes)
    

@app.route('/login', methods =['GET', 'POST'])
def login():
	msg = ''
	if request.method == 'POST' and 'username' in request.form and 'password' in request.form:
		username = request.form['username']
		password = request.form['password']
		cursor = conn.cursor()
		cursor.execute('SELECT * FROM accounts WHERE username = % s AND password = % s', (username, password, ))
		account = cursor.fetchone()
		if account:
			session['loggedin'] = True
			session['id'] = account['id']
			session['username'] = account['username']
			msg = 'Logged in successfully !'
			return render_template('index.html', msg = msg)
		else:
			msg = 'Incorrect username / password !'
	return render_template('login.html', msg = msg)



@app.route('/logout')
def logout():
	session.pop('loggedin', None)
	session.pop('id', None)
	session.pop('username', None)
	return redirect(url_for('login'))

@app.route('/register', methods =['GET', 'POST'])
def register():
	msg = ''
	if request.method == 'POST' and 'username' in request.form and 'password' in request.form and 'email' in request.form :
		username = request.form['username']
		password = request.form['password']
		email = request.form['email']
		cursor = conn.cursor()
		cursor.execute('SELECT * FROM accounts WHERE username = % s', (username, ))
		account = cursor.fetchone()
		if account:
			msg = 'Account already exists !'
		elif not re.match(r'[^@]+@[^@]+\.[^@]+', email):
			msg = 'Invalid email address !'
		elif not re.match(r'[A-Za-z0-9]+', username):
			msg = 'Username must contain only characters and numbers !'
		elif not username or not password or not email:
			msg = 'Please fill out the form !'
		else:
			cursor.execute('INSERT INTO accounts VALUES (NULL, % s, % s, % s)', (username, password, email, ))
			conn.commit()
			msg = 'You have successfully registered !'
	elif request.method == 'POST':
		msg = 'Please fill out the form !'
	return render_template('register.html', msg = msg)
