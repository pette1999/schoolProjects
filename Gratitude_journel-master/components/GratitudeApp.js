import Head from 'next/head'
import Greeting from './Greetings'
import History from './History'
import Input from './Input'
import {useEffect, useState} from 'react'
import {supabase} from '../utils/supabaseClient'
import {Auth} from '@supabase/ui'

export default function GratitudeApp({ user }) {
  const [gratitudes, setGratitudes] = useState ([])
  const [hasSubmittedToday, setHasSubmittedToday] = useState (false)
  const [loading, setLoading] = useState (true)
  const [error, setError] = useState(null)

  useEffect(() => {
    // run the fetchGratitude function
    // after the initial render of the app
    // so we have the access to the logged in user
    fetchGratitudes()
  }, [loading])
  // everytime loading is true, rerendering fetchGratitudes

  const fetchGratitudes = async () => {
    // get the gratitudes data from superbase
    // set the value of gratitude state to that data
    let { data: gratitudes, error } = await supabase
    .from('gratitudes')
    .select('entry,date_insert_ts')

    if(!error) {
      /* 1000: See if time since last submit */
      setGratitudes(gratitudes)
      setLoading(false)
      let mostResentRecordTime = new Date(gratitudes.slice(-1)[0].date_insert_ts).getTime()
      let currentTime = new Date().getTime()
      console.log(mostResentRecordTime)
      console.log(currentTime)
      let difference = currentTime - mostResentRecordTime
      if(difference <= 86400000) {
        setHasSubmittedToday(true)
      } else {
        setHasSubmittedToday(false)
      }
    } else {
      // there is an error
      console.log(error)
      setLoading(false)
      setError(error)
    }
  }

  const addGratitude = async (entry) => {
    // let newGratitudes = [...gratitudes, entry] //... deconstruct the gratitudes array into items
    // setGratitudes(newGratitudes)
    // setHasSubmittedToday(true)

    const { data, error } = await supabase
    .from('gratitudes')
    .insert([
      {
        id: user.id,
        entry: entry
      },
    ])

    if (error) {
      console.log(error)
      setError(error)
    } else {
      setGratitudes([...gratitudes, {'entry': entry, 'date_insert_ts': null}])
      setLoading(false)
      setHasSubmittedToday(true)
    }
  }

  /* Application is still fetching data */
  if (loading) {
    return <p>Loading...</p>
  }

  /* Something went wrong while fetching data */
  if (error) {
    return <p>{error}</p>
  }

  /* Everything went as expected, show full app */
  return (
    <div className="bg-gray-700 min-w-screen">
      <main className="red container mx-auto max-w-prose px-4">
        <Greeting 
          user = {user}
          gratitudes = {gratitudes}
          hasSubmittedToday = {hasSubmittedToday}
        ></Greeting>
        <div className="spacer"></div>
        {
          !hasSubmittedToday && <Input handleSubmit={addGratitude}></Input>
        }
        <div className="spacer"></div>
        {
          (gratitudes.length > 0) && (
            <History gratitudes={gratitudes}></History>
          )
        }
      </main>
      <style jsx>{`
        .spacer {
          height: 20px;
        }
      `}</style>
    </div>
  )
}