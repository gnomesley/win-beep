/**
 * Plays back a beep to the user. (float arguments will be cast into integer)
 * @param frequency The frequency of the beep in hertz. Can be anywhere from 37 through 32,767 (0x25 through 0x7FFF). Default is 600 Hz.
 * @param duration The length of the beep in milliseconds. Should be a positive number. Default is 1000 ms.
 */
export const beep = (frequency = 600, duration = 1000) => {
  if (process.platform === 'win32') {
    const winBeep = require('../build/Release/winBeep')
    winBeep(frequency, duration)
  } else {
    throw Error('winBeep is win32-only.')
  }
}
