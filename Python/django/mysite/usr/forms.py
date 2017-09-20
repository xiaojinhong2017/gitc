#coding=utf-8
from django import forms
from  bookapp.models import Book,Author

TOPIC_CHOICES = (
    ('leve1','好评'),
    ('leve2','中评'),
    ('leve3','差评'),
)

class RemarkForm(forms.Form):
    subject = forms.CharField(max_length = 100,label = '标题')
    mail = forms.EmailField(label = '邮件')
    topic = forms.ChoiceField(choices = TOPIC_CHOICES,label = '评价')
    message = forms.CharField(label = '内容',widget = forms.Textarea)
    cc_myself = forms.BooleanField(required = False,label = '订阅')

class AuthorForm(forms.ModelForm):
    class Meta:
        model = Author
        fields = '__all__'
        labels = {
            'first_name':'标题',
        }
class RegForm(forms.Form):
    username=forms.CharField(widget=forms.TextInput(attrs={"placeholder":"Username","required":"required"}),max_length=50,error_messages = {"required":"Username can not be empty"})
    password=forms.CharField(widget=forms.PasswordInput(attrs={"placeholder":"Password","required":"required"}),max_length=20,error_messages = {"required":"password can not be empty"})
    email=forms.EmailField(widget=forms.TextInput(attrs={"placeholder":"Email","required":"required"}),max_length=50,error_messages = {"required":"Email can not be empty"})
    tel=forms.CharField(widget=forms.TextInput(attrs={"placeholder":"telephone","required":"required"}),max_length=50,error_messages = {"required":"telephone can not be empty"})
    avatar = forms.ImageField(required = False)
