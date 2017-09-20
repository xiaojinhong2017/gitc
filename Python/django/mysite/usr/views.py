# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.shortcuts import render,redirect
from django.http import HttpResponse,HttpResponseRedirect
from forms import *
from bookapp.models import Author
from django.views.decorators.csrf import csrf_exempt
from django.contrib.sessions.models import Session
from django.contrib import auth
from django.contrib.auth.hashers import make_password
from django.contrib.auth.decorators import login_required,permission_required
from usr.models import *
from django.core.paginator import Paginator,InvalidPage,EmptyPage,PageNotAnInteger
# Create your views here.
def index(request):
    # index = dir(request)
    # return HttpResponse(index)
    return render(request,'search.html',{})
def search_form(request):
    print request.method
    if 'q' in request.GET and request.GET['q']:
        q = request.GET['q']
        return HttpResponse('I have get the %s '%q)
    else:
        return render(request,'search.html',{'error':True})

# def contact(request):
def get_request(request):
    scheme = request.scheme
    body = request.body
    path = request.path
    method = request.method
    content = request.content_type
    get = request.GET
    post = request.POST
    cook = request.COOKIES
    meta = request.META
    addr = request.META['REMOTE_ADDR']
    print request.get_host()
    # url = request.get('HTTP_REFERER','SORRY')

    return render(request,'request.html',locals())


def formset(request):
    if request.method == 'POST':
        form = RemarkForm(request.POST)
        if form.is_valid():
            cd  = form.cleaned_data
            print cd['subject']
            print cd['mail']
            print cd['topic']
            print cd['message']
            print cd['cc_myself']
            return HttpResponseRedirect('/formset')
    else:
        form = RemarkForm()

    return render(request,'formset.html',{'form':form})


def bookset(request):
    if request.method == 'POST':
        form = AuthorForm(request.POST)
        if form.is_valid():
            cd  = form.cleaned_data
            dic = {'first_name':cd['first_name'],'last_name':cd['last_name'],'email':cd['email']}
            Author.objects.create(**dic)
            return HttpResponseRedirect('/bookset/')
    else:
        form = AuthorForm()

    return render(request,'bookset.html',{'form':form})



#########session
# user_info = {
# 'pangzi':{'pwd':'pang123'},
# 'shouzi':{'pwd':'shou321'}
# }
# @csrf_exempt
# def login(request):
#     if request.method =='GET':
#         return render(request,'login.html')
#     if request.method == 'POST':
#         u = request.POST.get('username')
#         p = request.POST.get('pwd')
#         dic = user_info.get(u)
#         if not dic:
#             return render(request,'login.html')
#         if dic['pwd'] == p:
#             request.session['username'] = u
#             request.session['is_login'] = True
#             request.session.set_expiry(20)
#             res = redirect('/index/')
#             return res
#         else:
#             return render(request,'login.html')
# def index(request):
#     if request.session.get('is_login',None):
#         session = Session.objects.all()
#         print session
#         return render(request,'index1.html',{'current_user':request.session['username']})
#     else:
#         return redirect('/login/')
#
# def logout(request):
#     print dir(request.session)
#     request.session.clear()
#     return redirect('/login/')


# user_info = {
# 'pangzi':{'pwd':'pang123'},
# 'shouzi':{'pwd':'shou321'}
# }
# @csrf_exempt#form 表单错误处理
# def login(request):
#     if request.method == 'POST':
#         u = request.POST.get('username')
#         p = method == 'POST':
#         u = request.POST.get('username')
#         p = req.POST.get('pwd')
#         dic = user_info.get(u)
#         if not dic:
#             return render(request,'login.html')
#         if dic['pwd'] == p:
#             res = redirect('/index/')
#             res.set_cookie('user',u,max_age = 60,path = '/')
#             return res
#         else:
#             return render(request,'login.html')
# def index(request):
#     v = request.COOKIES.get('user')
#     if not v:
#         return redirect('/login/')
#     return render(request,'index1.html',{'current_user':v})


#########################
@login_required(login_url = '/login/')#登录后才允许
def login_test(request):
    return HttpResponse('Thank you for login')
def login(request):
    errors = []
    if request.method == 'POST':
        username = request.POST.get('username','')
        password = request.POST.get('password','')
        if not username:
            errors.append('Enter a username')
        if not password:
            errors.append('Enter a password')
        if not errors:
            if not request.user.is_authenticated():
                user = auth.authenticate(username =username ,password = password)#检查是否合法
                if user is not None and user.is_active:
                    auth.login(request,user)
                    # return HttpResponseRedirect(request.META.get("HTTP_REFERER",'/'))
                    return HttpResponseRedirect(request.GET.get("next",'/'))
                else:
                    return HttpResponse('username or password invalid')
            else:
                return HttpResponse('You have already login')
    return render(request,'user_login.html',{'errors':errors})
def logout(request):
    auth.logout(request)
    return HttpResponseRedirect('/login/')


#################
def thanks(request):
    return HttpResponse('Thanks for your register')
@permission_required('add_User',login_url = '/thanks')##change_user,delete_user 是否允许注册
def reg(request):
    try:
        if request.method == 'POST':
            reg_form = RegForm(request.POST)
            if reg_form.is_valid():
                cd = reg_form.cleaned_data
                User.objects.create(username=cd['username'],password=make_password(cd['password']),email=cd['email'],mobile=cd['tel'],avatar = cd['avatar'])

                return HttpResponseRedirect("/login/")
            else:
                return render(request,'failure.html',{'reason':reg_form.errors})
        else:
            reg_form = RegForm()
    except Exception as e:
        print e
    return render(request,'reg.html',locals())

def img(request):
    return render(request,'avatar.html')

def avatar(request):
    pass




def get_page(request):

    article_list = ['a1','a2','a3','a4','a5','a6','a7','a8']
    paginator = Paginator(article_list,5)
    p = int(request.GET.get('page',1))
    article_list = paginator.page(p)
    return render(request,'page.html',{'article_list':article_list})

# 2.某一个页面进行缓冲
from django.views.decorators.cache import cache_page
@cache_page(10)
def cache(request):
    import time
    ctime = time.time()
    return render(request,'cache.html',{'ctime':ctime})
