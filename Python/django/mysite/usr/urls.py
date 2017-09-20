#coding=utf-8
from django.conf.urls import url
from usr.views import *
urlpatterns = [
    url(r'^index/$',index),
    url(r'^search_form/$',search_form),
    # url(r'^contact/$',contact),
    # url(r'^contact/thanks/$',thanks),
]



urlpatterns += [
    url(r'^request$',get_request),
    url(r'^formset/$',formset),
    url(r'^bookset/$',bookset),
]

#login
# urlpatterns += [
# url(r'^login/$',login),
# url(r'^index/$',index),
# url(r'^logout/$',logout),
# ]

urlpatterns += [
url(r'^login/$',login),
url(r'^logout/$',logout),
url(r'^login_test/$',login_test),
url(r'^reg/$',reg,name = 'reg'),
url(r'^thanks/$',thanks),
url(r'^avatar/$',avatar),
url(r'^img/$',img),
url(r'^page/$',get_page),

]

urlpatterns += [
url(r'^cache/$',cache),
]
