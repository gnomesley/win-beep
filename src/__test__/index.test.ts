import { beep } from '../index'

const NORMAL_TEST_CASES = [
  [37, 1],
  [600, 600],
  [undefined, 1000],
  [600, undefined],
  [undefined, undefined],
  [32766, 100],
  [600.8, 600.2],
]

describe('normal test', () => {
  for (const [freq, dur] of NORMAL_TEST_CASES) {
    test(`frequency:${freq},duration:${dur}`, () => {
      expect(beep(freq, dur)).toBeUndefined()
    })
  }
})

const ERROR_TEST_CASE = [
  [-1, -1],
  [36, 1],
  [36, -1],
  [37, -1],
  [32768, -1],
  [32768, 1],
]

describe('arguments error test', () => {
  for (const [freq, dur] of ERROR_TEST_CASE) {
    test(`frequency:${freq},duration:${dur}`, () => {
      expect(() => {
        beep(freq, dur)
      }).toThrow()
    })
  }
})

describe('platform error test', () => {
  test('platform error test', () => {
    expect(() => {
      Object.defineProperty(process, 'platform', { value: 'linux' })
      beep(600, 100)
    }).toThrow(Error)
  })
})
