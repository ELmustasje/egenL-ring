import mysql.connector

conn = mysql.connector.connect(
    host="localhost",
    user="root",
    port="3306",
    password="TB-bt1a@",
    database="bikebrothers"
)


mycursor = conn.cursor()

def execute_query(query):
    mycursor.execute(query)
    return mycursor.fetchall()

def getbikes():
    mycursor.execute("SELECT * FROM bikes") 
    return mycursor.fetchall()

def insertIntoBike(year,frame,brand,model):
    mycursor.execute(f"INSERT INTO bikes(year,frame,brand,model) VALUES ('1','2','3','3');")
    conn.commit()