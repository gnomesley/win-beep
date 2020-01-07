{
  "targets": [
    {
      "target_name": "winBeep",
      "conditions": [
        ['OS=="win"',  {
          'sources': [ 
            'lib/winBeep.cc', 
          ]
        }]
      ]
    }
  ]
}