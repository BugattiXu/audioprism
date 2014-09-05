#include "AudioSource.hpp"
#include "AudioThread.hpp"
#include "ThreadSafeQueue.hpp"

AudioThread::AudioThread(AudioSource &source, ThreadSafeQueue<std::vector<double>> &samplesQueue, size_t readSize) : readSize(readSize), source(source), samplesQueue(samplesQueue) { }

void AudioThread::run() {
    std::vector<double> samples(readSize);
    while (true) {
        if (samples.size() != readSize)
            samples.resize(readSize);

        source.read(samples.data(), samples.size());
        samplesQueue.push(samples);
    }
}

unsigned int AudioThread::getSampleRate() {
    return source.getSampleRate();
}
