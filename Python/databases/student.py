import MySQLdb
import sys

db = MySQLdb.connect('localhost','root','123456','testdb')
cursor = db.cursor()


class Student:
    def __init__(self,cursor):
        # sql = 'create table user (name char(20) not null, passwd int, root char(1))'
        # cursor.execute(sql)
        self.cursor = cursor
    def do_login(self,name,passwd):
        sql = 'select * from user where name = "%s" and passwd = %d '%(name,passwd)
        try:
            cursor.execute(sql)
            results = cursor.fetchall()
            print results
            if(results != () ):
                self.do_show()
                if(results[0][2] == 'Y'):
                    print '''-----------------------------------------------------------------------
         ******commend: 1.insert 2.update 3.delete 4.exit******
------------------------------------------------------------------------'''
                    print 'please input number >>'
                    data = input()
                    if(data == 1):
                        name = raw_input('input your name >>')
                        age = input('input your age >>')
                        sex = raw_input('input your sex >> ')
                        score = input('input your score >>')
                        sql ='insert into student (name,age,sex,score) values ("%s",%d,"%s",%d)'%(name,age,sex,score)
                        try:
                            cursor.execute(sql)
                            db.commit()
                            self.do_show()
                        except:
                            db.rollback()
                    if(data == 2):
                        name = raw_input('input your name>>')
                        con1 = raw_input('input your update ziduanming>>')
                        con2 = raw_input('input your update content>>')
                        sql ='update student set "%s" = "%d" where name = "%s"'%(con1,con2,name)
                        try:
                            cursor.execute(sql)
                            db.commit()
                        except:
                            db.rollback()
                    if(data == 3):
                        name = raw_input('input your name>>')
                        sql ='delete from student  where name = "%s"'%(name)
                        try:
                            cursor.execute(sql)
                            db.commit()
                            self.do_show()
                        except:
                            db.rollback()
                    if(data == 4):
                        sys.exit(0)
            else:
                print '------please resign------'
                main()
        except:
            print 'Error:unable to fetch data'


    def do_resign(self,name,passwd,root):
        sql = 'insert into user (name,passwd,root) values ("%s","%d","%c")'%(name,passwd,root)
        try:
            cursor.execute(sql)
            db.commit()
            print 'resign success ,please login '
            main()
        except:
            db.rollback()

    def do_show(self):
        sql = 'select * from student'
        cursor.execute(sql)
        results = cursor.fetchall()
        # print results
        for row in results:
            name = row[0]
            age = row[1]
            sex = row[2]
            score = row[3]
            print ' %10s  |  %5d |  %5s  | %5d'%(name,age,sex,score)





stu = Student(cursor)
def main():
    print '''--------------------------------------------------------------
             commend: 1.login   2.resign   3.exit'
--------------------------------------------------------------'''
    data = input('input your cmd >>')
    if(data == 1):
        name = raw_input('input username>>')
        passwd = input('input password >>')
        stu.do_login(name,passwd)
    if(data == 2):
        name = raw_input('input username>>')
        passwd = input('input password >>')
        root = raw_input('input root >>')
        stu.do_resign(name,passwd,root)
    if(data ==  3):
        sys.exit(0)


if __name__ == '__main__':
    main()

cursor.close()
db.close()
