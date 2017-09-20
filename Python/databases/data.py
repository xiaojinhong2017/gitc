#coding=utf-8
import MySQLdb
import getpass

user = raw_input('user: ')
passwd = getpass.getpass('password:')

db = MySQLdb.connect('localhost',user, passwd,'testdb')
cursor = db.cursor()
# print dir(cursor)
cursor.execute('select version()')
print cursor.fetchone()
print cursor.fetchone()
print cursor.fetchone()



cursor.execute('select * from teacher')
# print cursor.fetchall()
# print cursor.fetchmany(3)
print cursor.description
print cursor.description[0][0]


cursor.execute('select * from teacher')
print cursor.fetchone()
print cursor.fetchall()


# cursor.execute('select * from teacher')
# print cursor.fetchmany(3)



print '---------------'
#创建删除表，插入删除数据，updata数据，alter


#插入数据
sql = '''insert into stu (id,name,age,sex,score) values(5,'lili',23,'girl',90) '''
try:
    cursor.execute(sql)
    db.commit()
except:
    db.rollback()


#创建表
# cursor.execute('drop table if exists emp')

# sql = '''create table emp (name char(20) not null ,age int,sex char(1),num int)'''
# try:
#     cursor.execute(sql)
#     db.commit()
# except:
#     db.rollback()



#插入数据
sql1 = '''insert into emp (name,age,sex,num) values ('mac',20,'m',1)'''
try:
    cursor.execute(sql1)
    db.commit()
except:
    db.rollback()

sql2 = '''update emp set age = age + 1 where sex = 'm' '''
try:
    cursor.execute(sql2)
    db.commit()
except:
    db.rollback()



cursor.close()
db.close()
