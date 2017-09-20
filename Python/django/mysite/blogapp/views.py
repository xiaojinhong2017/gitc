# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.shortcuts import render
from datetime import datetime

# Create your views here.
from django.http import HttpResponse ,HttpResponseRedirect
from blogapp.models import *
from django.contrib import auth
from django.contrib.auth.hashers import make_password
from django.contrib.auth.decorators import login_required,permission_required

from django.views.decorators.csrf import csrf_exempt
def origin(request):
    a = request.GET.get('a',None)
    b = 0
    if a != None:

         b = int(a)
         if b == 0 :
             blog_list = Blog.objects.filter(id__lt = 10).order_by('time')
         elif b == 1:
             blog_list = Blog.objects.filter(tag = '我的生活' ).order_by('time')
         elif b == 2:
             blog_list = Blog.objects.filter(tag = '旅游心情' ).order_by('time')
         elif b == 3:
             blog_list = Blog.objects.filter(tag = '技术达人' ).order_by('time')
         elif b == 4 :
             blog_list = Blog.objects.filter(tag = '电影推荐' ).order_by('time')
         return render(request,'index.html',{'title':b,'blog_list':blog_list})
    else:
         b = 0

    blog_list = Blog.objects.filter(id__lt = 10).order_by('time')
    return render(request,'index.html',{'title':b,'blog_list':blog_list})
def content(request,arg):
    if arg != None:
        blog_item = Blog.objects.filter(id = arg)[0]
        blog_item.see = blog_item.see + 1

        print blog_item.see
        Blog.objects.filter(id = arg).update(see = blog_item.see)
        comment_list = Comment.objects.filter(blog_id = arg)
        print comment_list

        # print blog_item[0]
    return render(request,'list.html',{'blog_item':blog_item,'comment_list':comment_list})


# @csrf_exempt
@login_required(login_url = '/blog/login/')
def login_write(request):
    return render(request,'write.html',)
def login(request):
    errors = []
    if request.method == 'POST':
        username = request.POST.get('username','')
        password = request.POST.get('pwd','')
        if not username:
            errors.append('Enter a username')
        if not password:
            errors.append('Enter a password')
        if not errors:
            if not request.user.is_authenticated():
                user = auth.authenticate(username =username ,password = password)
                if user is not None and user.is_active:
                    auth.login(request,user)
                    # return HttpResponseRedirect(request.META.get("HTTP_REFERER",'/'))
                    return HttpResponseRedirect(request.GET.get("next",'/'))
                else:
                    return HttpResponse('username or password invalid')
            else:
                return HttpResponse('You have already login')
    return render(request,'login.html',{'errors':errors})
def logout(request):
    auth.logout(request)
    return HttpResponseRedirect('/blog/login/')


def submit(request):
    if request.method == 'POST':
            title = request.POST.get('title')
            if  title:
                content = request.POST.get('content')
                if  content:
                    tag = request.POST.get('optionsRadios')
                    if  tag:
                        dic = {"title":title,"content":content,'tag':tag,'see':0,"time":datetime.now()}
                        print dic
                        Blog.objects.create(**dic)
                    else:
                        return HttpResponseRedirect('/blog/submit')

    return HttpResponseRedirect('/blog/')
# def lvyou(request):
#     return render(request,'index.html',{})
# def jishu(request):
#     return render(request,'index.html',{})
# def movie(request):
#     return render(request,'index.html',{})
# def list(request):
#     return render(request,'list.html',{})
