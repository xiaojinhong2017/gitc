# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.shortcuts import render,render_to_response,redirect

# Create your views here.
from django.http import HttpResponse,HttpResponseRedirect,Http404
from django.template import loader
import datetime
from bookapp.models import *
from django.db.models import F,Q
from django.db import connection
import os
import uuid
import json
import datetime as dt
def hello(request):
    return HttpResponse('hello,this is your first web')

def get_time(request):
    now = datetime.datetime.now()
    # # html = '<html><body><h1>It is time %s</h1></body></html>'%now
    # t = loader.get_template('datetime.html')
    # html = t.render({'date':now})
    # return HttpResponse(html)



    # return render_to_response('datetime.html',{'date':now}):
    raise Http404()


    return render(request,'datetime.html',{'date':now})

def jump(request):
    # return render(request,'redirect.html',{})
    return redirect('/book/time/')
    # return HttpResponseRedirect('/book/time/')

def error(request):
    raise Http404()


def argument(request,a,b):
    print a
    print b
    if a > b:
        return HttpResponse('a > b')
    else:
        return HttpResponse('a < b')
# def argument1(request ,a,b,c):
    # print a
    # print b
    # print c
def argument1(request ,offset):
    print offset
    return HttpResponse('get the argument')

def template(request):
    a = 1
    b = [1,2,3,4]
    c = {'a':1,'b':2}
    def fun(a):
        return 'hello template %s'%a
    class A(object):
        age = 20

    obj = A()
    return render(request,'template.html',{'a':a,'b':b,'c':c,'d':fun('h5'),'e':obj})
def tag(request):
    a = 1
    b = [1,2,3,4]
    return render(request,'tag.html',locals())

def filter(request):
    a = 'hello'
    b = 1
    c = 'hello world'
    return render(request,'filter.html',locals())

def extend(request):
    return render(request,'time.html',{})


def include(request):
    return render(request,'nav.html',{})

def static(request):
    return render(request,'static.html',{})

def global_template(request):
    return render(request,'global.html',{})

def add_data(request,table):
    if table == 'author':
        Author.objects.create(first_name = 'lili',last_name = 'Wang',email = '123@123.com')
    elif table =='book':
        obj = Book(title = 'python',publication_date = datetime.datetime.now(),publisher_id = 1)
        obj.save()
    else:
        dic = {'name':'人民出版社', 'address':'三里屯','city':'Chaoyang','state_province':'Beijing','country':'China','website':'http://www.abc.com'}
        Publisher.objects.create(**dic)
    return HttpResponse('add data ok')


def del_data(request,table):
    Book.objects.filter(id = 3).delete()
    return HttpResponse('delete data ok')

def update_data(request):
    # Publisher.objects.filter(id__gt = 1).update(name = '工业出版社')
    obj = Book.objects.get(id = 2)
    obj.title = 'html'
    obj.save()

    return HttpResponse('update data ok')


def select_data(request):
    a = Book.objects.all()
    b = Book.objects.all().values('title')
    c = Book.objects.all().values_list('title','publication_date')
    d  = Author.objects.get(id = 1)
    e = Author.objects.exclude(id__lt = 1)
    Book.objects.filter().update(price = F('price') + 1)
    q = Q()
    q.connector = 'AND'
    q.children.append(('id',3))
    q.children.append(('last_name','xun'))
    f = Author.objects.filter(q)
    g = Book.objects.title_count('html')
    h = Book.objects.all().little()


    return render(request,'select.html',locals())


def foreign(request):
    book = Book.objects.get(id = 2)
    p = book.publisher
    author_list =  book.author.all()
    pub = Publisher.objects.get(id = 1)
    book_list = pub.books.all()
    auth = Author.objects.get(id = 1)
    book_list1 = auth.book_set.all()
    return render(request,'select.html',locals())
def sql(request):
    #查询
    sql = '''select * from bookapp_author'''
    author_list = Author.objects.raw(sql)
    with connection.cursor() as cursor:
        sql = "insert into bookapp_author (first_name ,last_name,email) values('Mo','Yan','123.1234@com')"
        cursor.execute(sql)
    return render(request,'select.html',locals())



def article(request):
    return render(request,"article.html",{})


def image(files,dir_name):
    #允许上传文件类型
    allow_suffix =['jpg', 'png', 'jpeg', 'gif', 'bmp']
    file_suffix = files.name.split(".")[-1]
    if file_suffix not in allow_suffix:
        return {"error": 1, "message": "图片格式不正确"}
    relative_path_file = upload_generation_dir(dir_name)
    path=os.path.join(settings.MEDIA_ROOT, relative_path_file)
    if not os.path.exists(path): #如果目录不存在创建目录
        os.makedirs(path)
    file_name=str(uuid.uuid1())+"."+file_suffix
    path_file=os.path.join(path, file_name)
    file_url = settings.MEDIA_URL + relative_path_file + file_name
    #写入操作，二进制形式，最终完成上传，真正保存图片
    open(path_file, 'wb').write(files.file.read())
    return {"error": 0, "url": file_url}
