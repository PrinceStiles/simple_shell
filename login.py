from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login , logout
from django.contrib import messages``


def login_user(request):
    pass

def logout_user(request):
    logout(request)
    messages.success(request, "you have been logged out ")
    return redirect('home')


def register_user(request):
    if request.method == 'POST':
        form = SignUpForm(request.POST)
        if form.is_valid():
            form.save()
            #Autenticat and login
            username = form.cleaned_data['username']
            password = form.cleaned_data['password1']
            user = authenticate(username= username, password = password)
            login(request, user)
            messages.success(request, "yo have esuccesfully entered")
            return redirect('home')
    else:
        form = SignUpForm()
        return render(request,  'register.html', {'form':form})
    
    return render(request,  'register.html', {'form':form})