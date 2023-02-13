import speech_recognition as sr

r = sr.Recognizer()

audio_file = sr.AudioFile('../../test.wav')
with audio_file as source:
    audio = r.record(source)
try:
    s = r.recognize_google(audio, language="ru-RU")
    print("Text: " + s)
except Exception as e:
    print("Exception: " + str(e))
