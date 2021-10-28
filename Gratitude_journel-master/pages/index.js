import Head from 'next/head'
import {useState} from 'react'
import {supabase} from '../utils/supabaseClient'
import {Auth} from '@supabase/ui'
import GratitudeApp from '../components/GratitudeApp'

export default function Home() {
  // gets the user object from Context 
  // if no user is logged in, user will be null
  // if a user is logged in , there will be an object with user info
  const { user } = Auth.useUser()

  // fetch data function example
  const fetchDataFromSupabase = async () => {
    let {
      data,
      error
    } = await supabase
      .from('TABLE_NAME')
      .select('COLUMN, ANOTHER_COLUMN')
    if (error) setError(error.message)
    else {
      setData(data)
      setLoading(false)
    }
  }

  return (
    <div className="bg-gray-700 min-h-screen min-w-screen">
      <Head>
        <title>Gratitude App</title>
        <link rel="icon" href="/favicon.ico" />
      </Head>

      <main className="red container mx-auto max-w-prose px-4 pt-12">
        <div id="spacer" className="h-12"/>
        {
          // display app if user is logged in, otherwise show login module
          user ? (
            // User is logged in, display our app and Logout button
            <div className="container mx-auto max-w-prose px-4">
              <GratitudeApp user={user}/>
              <div id="spacer" className="h-12"/>
              <button
                className="text-pink-300 font-semibold"
                onClick={async () => {
                  const { error } = await supabase.auth.signOut()
                  if (error) console.log('Error logging out:', error.message)
                }}
              >
                Logout
              </button>
            </div>
          ) : (
            <div className = "container mx-auto max-w-2xl flex flex-col justify-center items-center p-4" >
              <h1 className="text-white text-6xl font-black">Gratitude Journal</h1>
              <div id="spacer" className="h-12"/>
              <div className = "bg-white bg-white rounded-lg py-4 px-12" >
                <Auth supabaseClient={supabase} socialLayout="horizontal" socialButtonSize="xlarge"/>
              </div>
            </div>
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

// export default function IndexPage() {
//   const { user } = Auth.useUser()

//   return (
//     <div className = "bg-gray-700 min-h-screen min-w-screen">
//       <div id="spacer" className="h-12"/>
//       {
//         /* 
//          * Check if user is logged in or not. 
//          * If not, display the login UI
//          * If logged in, display the app 
//          * & pass the user in as props
//          */
//         !user ? (
//           <div className="container mx-auto max-w-2xl flex flex-col justify-center items-center p-4">
//             <h1 className="text-white text-6xl font-black">Gratitude Journal</h1>
//             <div id="spacer" className="h-12"/>
//             <div className="bg-white rounded-lg py-4 px-12">
//             {/* This is the Login UI Component from SupabaseUI */}
//             <Auth
//               supabaseClient={supabase}
//               socialLayout="horizontal"
//               socialButtonSize="xlarge"
//             />
//             </div>
//           </div>
//         ) : (
//           /* User is logged in, display our app and Logout button */
//           <div className="container mx-auto max-w-prose px-4">
//             <GratitudeApp user={user}/>
//             <div id="spacer" className="h-12"/>
//             <button
//               className="text-pink-300 font-semibold"
//               onClick={async () => {
//                 const { error } = await supabase.auth.signOut()
//                 if (error) console.log('Error logging out:', error.message)
//               }}
//             >
//               Logout
//             </button>
//           </div>
//         )
//       }
//     </div>
//   )
// }