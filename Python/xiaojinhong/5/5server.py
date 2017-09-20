#coding=utf-8
#多进程实现socket
import socket,traceback,os,sys
import MySQLdb
db = MySQLdb.connect('localhost','root','123456','testdb')
cursor = db.cursor()

class User:
    def __init__(self,cursor):
        self.cursor = cursor
    def do_login(self,name,passwd):
        sql = 'select * from usr where name = "%s" and passwd = %s '%(name,passwd)
        try:
            cursor.execute(sql)
            results = cursor.fetchall()
            if(results != () ):
                return 'login success'
            else:
                return 'login failed please check your username and passwd or resign'

        except:
            print 'Error:unable to fetch data'

    def do_resign(self,name,passwd):
            sql = 'insert into usr (name,passwd) values ("%s","%s")'%(name,passwd)
            try:
                cursor.execute(sql)
                db.commit()
                return 'resign success ,please login '
            except:
                db.rollback()

usr = User(cursor)
def reap():
    while True:
        try:
            result = os.waitpid(-1,os.WNOHANG)
            if not result[0]:break
        except:
            break
        print('Reaped child process %d'%result[0])


host = ''
port = 8110


s = socket.socket()
s.bind((host,port))
s.listen(5)

print('Parent at %d listening for connections'%os.getpid())

while True:
    try:
        c,addr = s.accept()
    except KeyboardInterrupt:
        raise
    except:
        traceback.print_exc()
        continue
    reap()

    pid = os.fork()

    if pid:
        c.close()
        continue
    else:
        s.close()

        try:
            print("Child from %s being hanled PID %d"%(c.getpeername(),os.getpid()))

            while True:
                data = c.recv(1024)
                if not len(data):
                    break;
                print(data)
                if data == '1':
                    c.send('input your name and password')
                    user = c.recv(1024)
                    arg = user.split(' ')
                    message = usr.do_login(arg[0],arg[1])
                    print message
                if data == '2':
                    c.send('input your name and password')
                    user = c.recv(1024)
                    arg = user.split(' ')
                    message = usr.do_resign(arg[0],arg[1])
                    print message


        except (KeyboardInterrupt,SystemExit):
            raise
        except:
            traceback.print_exc()
        c.close()
        sys.exit(0)
