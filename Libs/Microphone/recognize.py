import speech_recognition as sr

r = sr.Recognizer()
audio_file = sr.AudioFile('client.wav')
with audio_file as source:
    audio = r.record(source)
try:
    s = r.recognize_google(audio, language="en-EN")
    #print("Text: " + s)
    f = open("text.txt", "a")
    f.write(s)
    f.close()
except Exception as e:
    print("Exception: " + str(e))
