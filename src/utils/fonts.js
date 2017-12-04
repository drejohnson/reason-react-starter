const FontFaceObserver = require('fontfaceobserver')

const Fonts = () => {
  const link = document.createElement('link')
  link.href =
    'https://fonts.googleapis.com/css?family=Lato:300,400,700,900|Poppins:300,400,500,600,700'
  link.rel = 'stylesheet'

  document.head.appendChild(link)

  const lato = new FontFaceObserver('Lato')
  const poppins = new FontFaceObserver('Poppins')

  lato.load().then(() => {
    document.documentElement.classList.add('lato')
  })
  Promise.all([
    lato.load().then(() => {
      document.documentElement.classList.add('lato')
    }),
    poppins.load().then(() => {
      document.documentElement.classList.add('poppins')
    })
  ]).then(() => console.log('Family Lato & Poppins have loaded'))
}

export default Fonts
